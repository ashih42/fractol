# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashih <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/30 19:32:11 by ashih             #+#    #+#              #
#    Updated: 2018/02/08 07:50:21 by ashih            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fractol

CFLAGS = -Wall -Werror -Wextra
HEADERS = -I$(INCLUDE) -I$(LIBFT)/includes -I$(MINILIBX)

INCLUDE = include
LIBFT = libft
MINILIBX = minilibx

SRC_CFILES = brot_3.c \
			 brot_4.c \
			 brot_8.c \
			 burning_ship.c \
			 c_ops.c \
			 color.c \
			 debug.c \
			 draw.c \
			 freedom.c \
			 keys.c \
			 keys2.c \
			 keys3.c \
			 keys4.c \
			 keys5.c \
			 main.c \
			 mandelbrot.c \
			 mandeldrop.c \
			 mouse.c \
			 mouse2.c \
			 parser.c \
			 render.c \
			 spiral.c \
			 triangulum.c \
			 tricell.c \
			 tricorn.c \
			 veil.c \
			 voidstar.c
SRC_OFILES = $(SRC_CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@echo "\x1b[1m\nBuilding $(LIBFT) library...\x1b[0m"
	make -C $(LIBFT)
	@echo "\x1b[1m\nBuilding $(MINILIBX) library...\x1b[0m"
	make -C $(MINILIBX)
	@echo "\x1b[1m\nBuilding $(NAME)...\x1b[0m"
	$(CC) $(CFLAGS) $(HEADERS) -c $(addprefix src/, $(SRC_CFILES))
	$(CC) -o $(NAME) $(SRC_OFILES) -L$(LIBFT) -lft -L$(MINILIBX) -lmlx\
		-lpthread -framework OpenGL -framework AppKit

clean:
	@echo "\x1b[1m\nCleaning...\x1b[0m"
	make -C $(LIBFT) clean
	make -C $(MINILIBX) clean
	/bin/rm -f $(SRC_OFILES)

fclean: clean
	/bin/rm -f $(LIBFT)/libft.a
	/bin/rm -f $(MINILIBX)/libmlx.a
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
