# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorst <chorst@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 13:29:24 by chorst            #+#    #+#              #
#    Updated: 2024/04/16 11:13:57 by chorst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
REMOVE := rm -f

# ANSI Color Codes
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;93m
DEFAULT := \033[0m

# Compiler and flags:
CC := gcc
CFLAGS := -Wall -Werror -Wextra -Wunreachable-code -Ofast

# Path to the MLX42 library
LIBMLX := ./MLX42
LIBLIB := ./library

# Include directories
INCLUDE_DIRS := -I ./include -I $(LIBMLX)/include -I $(LIBLIB)

# Libraries required for compilation
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Find all source files (.c)
SOURCES :=	./files/main.c \
			./files/get_map_positions.c \
			./files/map_form_check.c \
			./files/map_path_check.c \
			./files/helper_function.c \
			./files/map_validator.c \
			./files/map_pictures.c \
			./files/map_functions.c

# Generate object files (.o) from source files
OBJECTS := $(SOURCES:.c=.o)

############################ Build targets: ############################

# Build both the library and executable
all: libmlx precomp $(NAME)

# Build the MLX42 library (if needed)
libmlx:
	@if [ ! -d "MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git MLX42; \
	else \
		echo "Directory MLX42 already exists."; \
	fi
		@cd MLX42 && cmake -B build && cmake --build build -j4 \

# Pre-compilation step
precomp:
	@if ls $(OBJECTS) 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(Everything is up to date)\n"; \
	else \
		printf "$(YELLOW)\nCompiled files:\n"; \
		printf "$(YELLOW)\n(so_long)\n"; \
	fi

# Compilation rule (depends on precomp)
%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@printf "$(GREEN)$(notdir $<)$(DEFAULT)\n"

# Link object files and libraries to create the executable
OBJECTS_GNL = gnl
OBJECTS_LIBFT = libft
OBJECTS_PRINTF = printf
GNLINCLUDE = -L$(OBJECTS_GNL) -lget_next_line
LIBFTINCLUDE = -L$(OBJECTS_LIBFT) -lft
PRINTFINCLUDE = -L$(OBJECTS_PRINTF) -lprintf

# Makes the librarys for the other Projects
$(NAME): $(OBJECTS)
	@$(MAKE) -C $(OBJECTS_GNL)
	@$(MAKE) -C $(OBJECTS_LIBFT)
	@$(MAKE) -C $(OBJECTS_PRINTF)
	@$(CC) $(OBJECTS) $(LIBS) -o $(NAME) $(GNLINCLUDE) $(LIBFTINCLUDE) $(PRINTFINCLUDE)

# Compile the files for librarys
$(OBJECTS_GNL):
	@$(MAKE) -C $(OBJECTS_GNL)
$(OBJECTS_LIBFT):
	@$(MAKE) -C $(OBJECTS_LIBFT)
$(OBJECTS_PRINTF):
	@$(MAKE) -C $(OBJECTS_PRINTF)

############################ Cleaning targets: ############################

# Clean intermediate files
clean:
	@printf "$(YELLOW)\nCleaned files:\n"
	@if ls $(OBJECTS) 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(so_long.o)\n$(DEFAULT)"; \
		for file in $(notdir $(OBJECTS)); do \
			$(RM) $$file; \
			printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
		done; \
		$(MAKE) -C $(OBJECTS_GNL) clean; \
		$(MAKE) -C $(OBJECTS_LIBFT) clean; \
		$(MAKE) -C $(OBJECTS_PRINTF) clean; \
		$(REMOVE) $(OBJECTS); \
	else \
		printf "$(YELLOW)(Nothing needs to be cleaned)\n"; \
	fi


# Clean all generated files
fclean:
	@rm -rf MLX42
	@printf "$(YELLOW)\nForced cleaned files:\n"
	@if ls $(OBJECTS) 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(so_long.o)\n$(DEFAULT)"; \
		for file in $(notdir $(OBJECTS)); do \
			$(RM) $$file; \
			printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
		done; \
		printf "$(YELLOW)(so_long.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(REMOVE) $(NAME); \
		$(MAKE) -C $(OBJECTS_GNL) fclean; \
		$(MAKE) -C $(OBJECTS_LIBFT) fclean; \
		$(MAKE) -C $(OBJECTS_PRINTF) fclean; \
		$(REMOVE) $(OBJECTS); \
	elif ls $(NAME) 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(so_long.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(REMOVE) $(NAME); \
		$(MAKE) -C $(OBJECTS_GNL) fclean; \
		$(MAKE) -C $(OBJECTS_LIBFT) fclean; \
		$(MAKE) -C $(OBJECTS_PRINTF) fclean; \
	else \
		printf "$(YELLOW)(Everthing got cleaned)\n$(DEFAULT)"; \
	fi

# Rebuild from scratch
re: clean all

# Declare targets as "phony"
.PHONY: all, clean, fclean, re
