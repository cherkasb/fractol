# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/24 17:06:27 by bcherkas          #+#    #+#              #
#    Updated: 2018/05/03 15:08:27 by bcherkas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re kappa rekappa

CC=gcc -Wall -Wextra -Werror -I./libft -I./includes -o2

MLX=-I/usr/local/include -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

LIBFT=./libft/libft.a

SRC=fractol.c triggers.c triggers2.c escapewindow.c color.c help.c draw_function.c mouse_events.c

SETS=julia.c mandelbrot.c tricorn.c heart_mandelbrot.c perpendic_mandel.c burning_ship.c

SRCS=$(addprefix ./srcs/, $(SRC)) $(addprefix ./srcs/, $(SETS))

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

nameclean:
	@rm -f $(OBJ)
	@echo "cleaned"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ./libft fclean
	@echo "fclean done"
re: fclean all

kappa: all clean

rekappa: re clean
