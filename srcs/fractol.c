/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:05:16 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 18:55:35 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init(t_info *inf)
{
	inf->mlxptr = NULL;
	inf->winptr = NULL;
	inf->funcs[0].func = mandelbrot_wrap;
	inf->funcs[1].func = julia_wrap;
	inf->funcs[2].func = tricorn_wrap;
	inf->funcs[3].func = heart_mandelbrot_wrap;
	inf->funcs[4].func = perp_mandel_wrap;
	inf->funcs[5].func = burn_ship_wrap;
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
	mlx_hook(winp, 6, 0, mouse_julia, (void *)inf);
	mlx_mouse_hook(winp, mouse_events, (void *)inf);
}

static void		graphics(t_info *inf)
{
	inf->mlxptr = mlx_init();
	inf->winptr = mlx_new_window(inf->mlxptr, MAP_LEN, MAP_LEN, "Fractol");
	create_image(inf);
	inf->wrap_func(inf);
	bind(inf);
	mlx_loop(inf->mlxptr);
}

int				main(int ac, char **av)
{
	t_info	inf;

	if (ac != 2)
		usage();
	str_to_lower(av[1]);
	if (!check_if_valid(&inf, av[1]))	
		fractal_names();
	init(&inf);
	graphics(&inf);
}
