/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 20:53:38 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/16 19:43:46 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		orange_colored(t_info *inf, int coef, int max)
{
	t_rgb	rgb;

	rgb = new_color(0, 0, 0);
	if (max == coef && inf->white_center == 0)
		return (0);
	else if ((max == coef && inf->white_center) || 2 > max - coef)
		return (0xFFFFFF);
	while (max >= 2)
	{
		if (coef <= max >> 1)
		{
			rgb.red = 253 / (max >> 1) * coef;
			rgb.green = 254 / (max >> 1) * coef;
			rgb.blue = 112 / (max >> 1) * coef;
			break ;
		}
		max = max >> 1;
		coef -= max;
	}
	rgb.clr = ((rgb.red << 16) | (rgb.green << 8)) | rgb.blue;
	return (rgb.clr);
}
