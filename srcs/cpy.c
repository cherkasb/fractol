/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:23:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/25 20:02:34 by bcherkas         ###   ########.fr       */
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
	red = 0;
	green = 0;
	blue = 0;
	if (coef == max)
		return (0);
	if (type)
	{
		green = 255 / max * coef;
		blue = 255 / max * coef;
		red = 255 / max * coef;
	}
	clr = (red * 256 * 256) + (green * 256) + blue;
///	ft_printf("red: %d green: %d blue: %d\n", red, green, blue);
	return (clr);
}
