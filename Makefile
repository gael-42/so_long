# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemarian <lemarian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 16:07:38 by lemarian          #+#    #+#              #
#    Updated: 2024/10/07 14:30:34 by lemarian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

NAME = so_long

SRCS = main.c parsing.c utils.c free.c map_checking.c path_checking.c \
display.c move.c

LIBFT_DIR = ./new_libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR) - I/usr/include -Imlx

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
