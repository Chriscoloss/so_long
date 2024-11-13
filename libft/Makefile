# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chorst <chorst@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 14:17:29 by chorst            #+#    #+#              #
#    Updated: 2024/04/01 15:00:05 by chorst           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;93m
DEFAULT := \033[0m

SOURCES =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
			ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

BONUS =		ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c

LIBRARY =  libft.h

all: precomp $(NAME)

$(NAME) : $(SOURCES:.c=.o)
	@ar -rcs $(NAME) $(SOURCES:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@printf "$(GREEN)$(notdir $<)$(DEFAULT)\n"

bonus: $(BONUS:.c=.o)
	@ar -rcs $(NAME) $(BONUS:.c=.o)

clean:
	@printf "\n$(YELLOW)(libft.o)\n$(DEFAULT)"
	@for file in $(SOURCES:.c=.o) $(BONUS:.c=.o); do \
		$(RM) $$file; \
		printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
	done

fclean:
	@if ls *.o 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(libft.o)\n$(DEFAULT)"; \
		for file in $(SOURCES:.c=.o); do \
			$(RM) $$file; \
			printf "$(RED)%s\n$(DEFAULT)" "$$file"; \
		done; \
		printf "$(YELLOW)(libft.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(RM) $(NAME); \
	elif ls libft.a 1> /dev/null 2>&1; then \
		printf "$(YELLOW)\n(libft.a)\n$(DEFAULT)"; \
		printf "$(RED)%s\n$(DEFAULT)" "$(NAME)"; \
		$(RM) $(NAME); \
	fi

re: clean all

precomp:
	@printf "$(YELLOW)\n(libft)\n"
