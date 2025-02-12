# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 18:55:02 by gcesar-n          #+#    #+#              #
#    Updated: 2025/02/11 23:44:25 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = src/main.c src/parser.c src/utils.c \
		src/operations/sort_small.c src/operations/sort_large.c \
		src/operations/op_swaps.c src/operations/op_pushes.c \
		src/operations/op_rotate.c src/operations/op_rev_rotate.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

src/operations/%.o: src/operations/%.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
