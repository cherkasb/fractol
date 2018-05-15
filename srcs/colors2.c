/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:53:38 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/15 21:05:25 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		orange_colored(t_info *inf, int coef, int max)
{
	t_rgb	rgb;

	rgb = new_color(0, 0, 0);
	if (max == coef && inf->white_center == 0)
		return (0);
	else if ((max == coef && inf->white_center) || max < 2)
		return (0xFFFFFF);
	if (coef <= max >> 1)
	{
		rgb.red = 253 / (max >> 1) * coef;
		rgb.green = 254 / (max >> 1) * coef;
		rgb.blue = 112 / (max >> 1) * coef;
	}
	else
		orange_colored(inf, coef - (max >> 1), max >> 1);
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}

/*
int		orange_colored(t_info *inf, int coef, int max)
{
	int		save;
	t_rgb	rgb;

	rgb = new_color(0, 0, 0);
	if (max == coef && inf->white_center == 0)
		return (0);
	else if ((max == coef && inf->white_center) || max < 2)
		return (0xFFFFFF);
	if (coef <= max >> 1)
	{
		save = 255 / (max >> 1) * coef;
		rgb = new_color(save, save, 0);
	}
	else
		orange_colored(inf, coef - (max >> 1), max >> 1);
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}*/
