# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 18:55:02 by gcesar-n          #+#    #+#              #
#    Updated: 2025/02/11 00:04:08 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
# CFLAGS = -Wall -Werror -Wextra

SRC = src/main.c src/parser.c src/utils.c
OBJECTS = src/main.o src/parser.o src/utils.o

all: $(NAME)

$(NAME): $(OBJECTS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -Llibft -lft

libft/libft.a:
	make -C libft

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
