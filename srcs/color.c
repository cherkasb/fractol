/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:23:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/26 18:51:20 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		dark_red_white(int coef, int max)
{
	int		clr;
	int		type;
	int		red;
	int		green;
	int		blue;

	type = (coef > max / 2);
	green = 0;
	blue = 0;
	red = 255;
	if (coef == max)
		return (0xFFFFFF);
	if (coef > max / 2)
	{
		green = 255 / max * coef;
		blue = 255 / max * coef;
	}
	else if (coef < max / 2)
		return (0);
	clr = (red * 256 * 256) + (green * 256) + blue;
	return (clr);
}
