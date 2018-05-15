/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:37:17 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/15 18:14:01 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	white_center(t_info *inf)
{
	inf->white_center = inf->white_center == 1 ? 0 : 1;
	draw_function(inf);
	return (1);
}

static int	sec_color_part(t_info *inf)
{
	inf->color_part = inf->color_part == 1 ? 0 : 1;
	draw_function(inf);
	return (1);
}

static int	change_func(int key, t_info *inf)
{
	int		i;

	i = 0;
	while (inf->funcs[i].func != inf->wrap_func && i < FRACTAL_NUMBER)
		i++;
	i += key == 33 ? -1 : 1;
	if (i < 0)
		i = FRACTAL_NUMBER - 1;
	else if (i >= FRACTAL_NUMBER)
		i = 0;
	inf->funcs[i].func(inf);
	return (1);
}

static int	change_color(int key, t_info *inf)
{
	if (key == 18)
		inf->color_func = red_colored;
	else if (key == 19)
		inf->color_func = green_colored;
	else if (key == 20)
		inf->color_func = white_colored;
	else if (key == 21)
		inf->color_func = three_colored;
	else if (key == 23)
		inf->color_func = orange_colored;
	draw_function(inf);
	return (1);
}

int			triggers2(int key, t_info *inf)
{
	if (key == 33 || key == 30)
		return (change_func(key, inf));
	else if ((key >= 18 && key <= 23) || key == 25 || key == 26 || key == 28 ||
			key == 29)
		return (change_color(key, inf));
	else if (key == 24)
		return (white_center(inf));
	else if (key == 27)
		return (sec_color_part(inf));
	return (0);
}
