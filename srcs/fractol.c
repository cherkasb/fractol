/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:05:16 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/26 18:49:31 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		bind(t_info *inf)
{
	void	*mlxp;
	void	*winp;

	mlxp = inf->mlxptr;
	winp = inf->winptr;
	mlx_hook(winp, 17, 1L << 17, exitwindow, (void *)inf);
	mlx_hook(winp, 2, 5, triggers, (void *)inf);
}

static void		graphics(t_info *inf)
{
	inf->mlxptr = mlx_init();
	inf->winptr = mlx_new_window(inf->mlxptr,
			MAP_LEN, MAP_LEN, "Fractol");
	mandelbrot(inf);
	bind(inf);
	mlx_loop(inf->mlxptr);
}

int		main(int ac, char **av)
{
	t_info	inf;

	init_inf(&inf);
	if (ac && av)
		;
	graphics(&inf);
}
