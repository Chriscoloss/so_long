# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorst <chorst@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:29:45 by chorst            #+#    #+#              #
#    Updated: 2024/04/01 15:00:35 by chorst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libprintf.a
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
AR			= ar -rcs

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;93m
DEFAULT := \033[0m

SRC	= ft_printf_d_i.c ft_printf_s.c ft_printf_u.c ft_printf_x_low.c \
		ft_printf_x_up.c ft_printf_p.c ft_printf.c

all: precomp $(NAME)

 $(NAME):	$(SRC:.c=.o)
	@$(AR) $(NAME) $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@printf "$(GREEN)$(notdir $<)$(DEFAULT)\n"


clean:
	@printf "\n$(YELLOW)(printf.o)\n$(DEFAULT)"
	@for file in $(SRC:.c=.o); do \
		$(RM) $$file; \
		printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
	done

fclean:
	@if ls *.o 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(libft.o)\n$(DEFAULT)"; \
		for file in $(SRC:.c=.o); do \
			$(RM) $$file; \
			printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
		done; \
		printf "$(YELLOW)(libft.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(RM) $(NAME); \
	elif ls $(NAME) 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(libft.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(RM) $(NAME); \
	fi

re: clean all

precomp:
	@printf "$(YELLOW)\n(printf)\n"
