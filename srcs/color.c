/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:23:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/28 17:29:35 by bcherkas         ###   ########.fr       */
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
		return (0);
	if (coef > max / 2)
	{
		green = 255 / max * coef;
		blue = 255 / max * coef;
	}
	else if (coef < max / 2)
		return (0);
	clr = (red << 16) + (green << 8) + blue;
	return (clr);
}
