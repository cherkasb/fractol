/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:23:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 19:18:45 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		dark_red_white(int coef, int max)
{
	int		clr;
	int		red;
	int		green;
	int		blue;

	green = 0;
	blue = 0;
	red = 255;
	if (coef == max)
		return (0xFFFFFF);
	if (max > 75)
		max -= (max / 75) * 20;
	if (coef > max / 2)
	{
		green = 255 / max * coef;
		blue = 255 / max * coef;
	}
	else
	{
		red = 0;
	//	blue = 255 / max * coef;
	//	red = 0;
	}
	clr = (red << 16) + (green << 8) + blue;
	return (clr);
}
