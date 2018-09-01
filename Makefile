# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 17:06:27 by bcherkas          #+#    #+#              #
#    Updated: 2018/05/16 19:50:54 by bcherkas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC=clang -Wall -Wextra -Werror -o3

MLX=-lXext -lX11 -I./libmlx/ -lm -lpthread

HEAD= -I./libmlx -I./includes -I./gnl -I./libft/includes

LIBFT=./libft/libft.a

SRC=fractol.c triggers.c triggers2.c escapewindow.c color.c color_help.c help.c draw_function.c mouse_events.c colors2.c

SETS=julia.c julia2.c mandelbrot.c tricorn.c heart_mandelbrot.c perpendic_mandel.c burning_ship.c celtic.c

SRCS=$(addprefix ./srcs/, $(SRC)) $(addprefix ./srcs/, $(SETS))

OBJ=$(SRCS:.c=.o)

NAME=fractol

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(HEAD) -g $(MLX) -o $@ $^ ./libmlx/libmlx_Linux.a
	@echo "all done"

%.o: %.c
	@$(CC) $(HEAD) -c -o $@ -pthread $<

$(LIBFT):
	@$(MAKE) --no-print-directory -C ./libft

clean:
	@rm -f $(OBJ)
	@$(MAKE) --no-print-directory -C ./libft clean
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C ./libft fclean
	@echo "fclean done"
re: fclean all
