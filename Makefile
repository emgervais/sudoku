# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egervais <egervais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 19:11:19 by egervais          #+#    #+#              #
#    Updated: 2023/04/11 16:37:01 by egervais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= sudoku
CFLAGS	:= -Wextra -Wall -O3 -fsanitize=address -g
LIBMLX	:= ./MLX42

LIBS	:= $(LIBMLX)/build/libmlx42.a -lm -lglfw -pthread -ldl
SRCS	:= main.c
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx