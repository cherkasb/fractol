/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:51:20 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/17 16:01:42 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		red_colored(t_info *inf, int coef, int max)
{
	t_rgb	rgb;

	rgb.green = 0;
	rgb.blue = 0;
	rgb.red = 0;
	if (max == coef && inf->white_center == 0)
		return (0);
	else if (max == coef && inf->white_center)
		return (0xFFFFFF);
	if (coef > max >> 1 && inf->color_part)
	{
		max = 255.0 / (double)max * (double)coef;
		rgb.red = 255;
		rgb.green = max;
		rgb.blue = max;
	}
	else
		rgb.red = 255.0 / (double)max * (double)coef;
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}

int		green_colored(t_info *inf, int coef, int max)
{
	t_rgb	rgb;

	rgb.green = 0;
	rgb.blue = 0;
	rgb.red = 0;
	if (max == coef && inf->white_center == 0)
		return (0);
	else if (max == coef && inf->white_center)
		return (0xFFFFFF);
	if (coef > max >> 1 && inf->color_part)
	{
		max = 255.0 / (double)max * (double)coef;
		rgb.green = 255.0;
		rgb.red = max;
		rgb.blue = max;
	}
	else
		rgb.green = 255.0 / (double)max * (double)coef;
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}

int		white_colored(t_info *inf, int coef, int max)
{
	int		save;
	t_rgb	rgb;

	rgb = new_color(0, 0, 0);
	if (max == coef && inf->white_center == 0)
		return (0);
	else if (max == coef && inf->white_center)
		return (0xFFFFFF);
	save = 255.0 / (double)max * (double)coef;
	rgb = new_color(save, save, save);
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}

int		three_colored(t_info *inf, int coef, int max)
{
	t_rgb	rgb;

	rgb.red = 0;
	rgb.green = 0;
	rgb.blue = 0;
	if (max == coef && inf->white_center == 0)
		return (0);
	else if (max == coef && inf->white_center)
		return (0xFFFFFF);
	if (coef > max >> 1 && inf->color_part)
	{
		rgb.red = 1 + 127.0 / (double)max * (double)coef;
		rgb.green = 188 + 33.5 / (double)max * (double)coef;
		rgb.blue = 198 + 23.5 / (double)max * (double)coef;
	}
	else
	{
		rgb.red = 1.0 / (double)max * (double)coef;
		rgb.blue = 188.0 / (double)max * (double)coef;
		rgb.green = 198.0 / (double)max * (double)coef;
	}
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}

int		recursive_colored(t_info *inf, int coef, int max)
{
	int		save;
	t_rgb	rgb;

	rgb = new_color(0, 0, 0);
	if (max == coef && inf->white_center == 0)
		return (0);
	else if ((max == coef && inf->white_center) || max - coef < 2)
		return (0xFFFFFF);
	while (max >= 2)
	{
		if (coef <= max >> 1)
		{
			save = 255.0 / (max >> 1) * (double)coef;
			rgb = new_color(save, save, save);
			break ;
		}
		max = max >> 1;
		coef -= max;
	}
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}
