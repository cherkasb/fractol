/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:05:16 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/28 20:25:14 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init(t_info *inf)
{
	inf->mlxptr = NULL;
	inf->winptr = NULL;
	inf->mlb.max_x = 1;
	inf->mlb.min_x = -2.0;
	inf->mlb.min_y = -1.2;
	inf->mlb.max_y = inf->mlb.min_y + (inf->mlb.max_x - inf->mlb.min_x);
	inf->mlb.rel_x = (inf->mlb.max_x - inf->mlb.min_x) /
		(double)(MAP_LEN - 1);
	inf->mlb.rel_y = (inf->mlb.max_y - inf->mlb.min_y) /
		(double)(MAP_LEN - 1);
	inf->mlb.max_iter = 30;
}

static void		create_image(t_info *inf)
{
	inf->img.pixel_mass = 8;
	inf->img.line_mass = inf->img.pixel_mass * MAP_LEN;
	inf->img.img_ptr = mlx_new_image(inf->mlxptr, MAP_LEN, MAP_LEN);
	inf->img.endi = 0;
	inf->img.img_mass = MAP_LEN * MAP_LEN;
	inf->img.img_arr = (int *)mlx_get_data_addr(inf->img.img_ptr,
			&(inf->img.pixel_mass), &(inf->img.line_mass), &(inf->img.endi));
}

static void		bind(t_info *inf)
{
	void	*mlxp;
	void	*winp;

	mlxp = inf->mlxptr;
	winp = inf->winptr;
	mlx_hook(winp, 17, 1L << 17, exitwindow, (void *)inf);
	mlx_hook(winp, 2, 5, triggers, (void *)inf);
	mlx_mouse_hook(winp, mouse_events, (void *)inf);
}

static void		graphics(t_info *inf, char *name)
{
	inf->mlxptr = mlx_init();
	inf->winptr = mlx_new_window(inf->mlxptr, MAP_LEN, MAP_LEN, "Fractol");
	create_image(inf);
	if (ft_strequ(name, "Mandelbrot"))
		mandelbrot(inf);
	bind(inf);
	mlx_loop(inf->mlxptr);
}

int				main(int ac, char **av)
{
	t_info	inf;

	if (ac != 2)
		usage();
	if (ft_strequ(av[1], "names"))
		fractal_names();
	if (!ft_strequ(av[1], "Mandelbrot") && !ft_strequ(av[1], "Julia"))
		name_error();
	init(&inf);
	graphics(&inf, av[1]);
}
