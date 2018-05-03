/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:23:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/02 19:36:25 by bcherkas         ###   ########.fr       */
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
	if (coef > max / 2)
	{
		rgb.red = 255;
		rgb.green = 255 / max * coef;
		rgb.blue = 255 / max * coef;
	}
	else if (inf->color_part)
		rgb.red = 255 / max * coef;
	rgb.clr = (rgb.red << 16) + (rgb.green << 8) + rgb.blue;
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
	if (coef > max / 2)
	{
		rgb.green = 255;
		rgb.red = 255 / max * coef;
		rgb.blue = 255 / max * coef;
	}
	else if (inf->color_part)
		rgb.green = 255 / max * coef;
	rgb.clr = (rgb.red << 16) + (rgb.green << 8) + rgb.blue;
	return (rgb.clr);
}

int		white_colored(t_info *inf, int coef, int max)
{
	t_rgb	rgb;

	rgb.green = 0;
	rgb.blue = 0;
	rgb.red = 0;
	if (max == coef && inf->white_center == 0)
		return (0);
	else if (max == coef && inf->white_center)
		return (0xFFFFFF);
	if (coef > max / 2)
	{
		rgb.green = 255 / max * coef;
		rgb.red = 255 / max * coef;
		rgb.blue = 255 / max * coef;
	}
	else if (inf->color_part)
	{
		rgb.red = 255 / max * coef;
		rgb.blue = 255 / max * coef;
		rgb.green = 255 / max * coef;
	}
	rgb.clr = (rgb.red << 16) + (rgb.green << 8) + rgb.blue;
	return (rgb.clr);
}

int		three_colored(t_info *inf, int coef, int max)
{
	t_rgb	rgb;

	rgb.red = 228;
	rgb.green = 172;
	rgb.blue = 113;
	if (max == coef && inf->white_center == 0)
		return (0);
	else if (max == coef && inf->white_center)
		return (0xFFFFFF);
	if (coef > max / 2)
	{
		rgb.green = rgb.green / max * coef;
		rgb.red = rgb.red / max * coef;
		rgb.blue = rgb.blue / max * coef;
	}
	else if (inf->color_part)
	{
		rgb.red = rgb.red / max * coef;
		rgb.blue = rgb.blue / max * coef;
		rgb.green = rgb.green / max * coef;
	}
	rgb.clr = (rgb.red << 16) + (rgb.green << 8) + rgb.blue;
	return (rgb.clr);
}
