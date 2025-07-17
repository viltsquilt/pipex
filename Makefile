# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/07 11:48:33 by vahdekiv          #+#    #+#              #
#    Updated: 2025/07/17 15:24:32 by vahdekiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft/
SRCS = main.c parsing.c pipex.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
		@rm -f *.o
		@make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME) $(LIBFT)

re: fclean all

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -g

.PHONY: all clean fclean re


