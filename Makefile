# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 18:55:02 by gcesar-n          #+#    #+#              #
#    Updated: 2025/02/14 18:19:26 by gcesar-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

# source files
SRCS = src/main.c src/parser.c src/utils.c \
		src/operations/sort_small.c src/operations/sort_large.c \
		src/operations/op_swaps.c src/operations/op_pushes.c \
		src/operations/op_rotate.c src/operations/op_rev_rotate.c \
		src/operations/op_utils.c src/utils_parse.c

# object directory
OBJ_DIR = objects

# object files
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/utils.o \
		$(OBJ_DIR)/sort_small.o $(OBJ_DIR)/sort_large.o \
		$(OBJ_DIR)/op_swaps.o $(OBJ_DIR)/op_pushes.o \
		$(OBJ_DIR)/op_rotate.o $(OBJ_DIR)/op_rev_rotate.o \
		$(OBJ_DIR)/op_utils.o $(OBJ_DIR)/utils_parse.o

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

# compilation
$(OBJ_DIR)/main.o: src/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/parser.o: src/parser.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/parser.c -o $(OBJ_DIR)/parser.o

$(OBJ_DIR)/utils.o: src/utils.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/utils.c -o $(OBJ_DIR)/utils.o

$(OBJ_DIR)/sort_small.o: src/operations/sort_small.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/operations/sort_small.c -o $(OBJ_DIR)/sort_small.o

$(OBJ_DIR)/sort_large.o: src/operations/sort_large.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/operations/sort_large.c -o $(OBJ_DIR)/sort_large.o

$(OBJ_DIR)/op_swaps.o: src/operations/op_swaps.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/operations/op_swaps.c -o $(OBJ_DIR)/op_swaps.o

$(OBJ_DIR)/op_pushes.o: src/operations/op_pushes.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/operations/op_pushes.c -o $(OBJ_DIR)/op_pushes.o

$(OBJ_DIR)/op_rotate.o: src/operations/op_rotate.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/operations/op_rotate.c -o $(OBJ_DIR)/op_rotate.o

$(OBJ_DIR)/op_rev_rotate.o: src/operations/op_rev_rotate.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/operations/op_rev_rotate.c -o $(OBJ_DIR)/op_rev_rotate.o

$(OBJ_DIR)/op_utils.o: src/operations/op_utils.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/operations/op_utils.c -o $(OBJ_DIR)/op_utils.o

$(OBJ_DIR)/utils_parse.o: src/utils_parse.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c src/utils_parse.c -o $(OBJ_DIR)/utils_parse.o

# create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft/libft.a:
	make -C libft

clean:
	rm -rf $(OBJ_DIR)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
