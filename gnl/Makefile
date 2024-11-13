# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorst <chorst@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 17:54:52 by chorst            #+#    #+#              #
#    Updated: 2024/04/01 15:00:29 by chorst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libget_next_line.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar -rcs

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;93m
DEFAULT := \033[0m

SRC	= get_next_line_utils.c get_next_line.c

all: precomp $(NAME)

 $(NAME):	$(SRC:.c=.o)
	@$(AR) $(NAME) $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@printf "$(GREEN)$(notdir $<)$(DEFAULT)\n"

clean:
	@printf "\n$(YELLOW)(get_next_line.o)\n$(DEFAULT)"
	@for file in $(SRC:.c=.o); do \
		$(RM) $$file; \
		printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
	done

fclean:
	@if ls *.o 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(get_next_line.o)\n$(DEFAULT)"; \
		for file in $(SRC:.c=.o); do \
			$(RM) $$file; \
			printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
		done; \
		printf "$(YELLOW)(get_next_line.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(RM) $(NAME); \
	elif ls libget_next_line.a 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(get_next_line.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(RM) $(NAME); \
	fi

re: clean all

precomp:
	@printf "$(YELLOW)\n(get_next_line)\n"
