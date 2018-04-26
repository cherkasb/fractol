# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 17:06:27 by bcherkas          #+#    #+#              #
#    Updated: 2018/04/26 19:08:01 by bcherkas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re kappa rekappa

CC=gcc -Wall -Wextra -Werror -I./libft -I./includes

MLX=-I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

LIBFT=./libft/libft.a

SRC=fractol.c triggers.c escapewindow.c init.c mandelbrot.c color.c

SRCS=$(addprefix ./srcs/, $(SRC))

OBJ=$(SRCS:.c=.o)

NAME=fractol

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -g $(MLX) -o $@ $^
	@echo "all done"

%.o: %.c
	@$(CC) -c -o $@ $<

d: $(SRCS) libft/*.c
	$(CC) $(MLX) -g $^ -o test

$(LIBFT):
	@$(MAKE) -C ./libft
	@echo "libft compiled"

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C ./libft clean
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "fclean done"
re: fclean all

kappa: all clean

rekappa: re clean
