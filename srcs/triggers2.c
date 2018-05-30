/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:37:17 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/16 19:43:56 by bcherkas         ###   ########.fr       */
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
	i += key == BRACKET_LEFT ? -1 : 1;
	if (i < 0)
		i = FRACTAL_NUMBER - 1;
	else if (i >= FRACTAL_NUMBER)
		i = 0;
	inf->funcs[i].func(inf);
	return (1);
}

static int	change_color(int key, t_info *inf)
{
	if (key == KEY_1)
		inf->color_func = red_colored;
	else if (key == KEY_2)
		inf->color_func = green_colored;
	else if (key == KEY_3)
		inf->color_func = white_colored;
	else if (key == KEY_4)
		inf->color_func = three_colored;
	else if (key == KEY_5)
		inf->color_func = recursive_colored;
	else if (key == KEY_6)
		inf->color_func = orange_colored;
	else
		return (0);
	if (key == KEY_5 || key == KEY_6)
		inf->color_type = 1;
	else
		inf->color_type = 0;
	draw_function(inf);
	return (1);
}

int			triggers2(int key, t_info *inf)
{
	if (key == BRACKET_RIGHT || key == BRACKET_LEFT)
		return (change_func(key, inf));
	else if (key >= KEY_1 && key <= KEY_6)
		return (change_color(key, inf));
	else if (key == KEY_PLUS)
		return (white_center(inf));
	else if (key == KEY_MIN)
		return (sec_color_part(inf));
	return (0);
}
