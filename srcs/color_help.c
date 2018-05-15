/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 18:24:26 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/15 19:56:08 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb	new_color(int red, int green, int blue)
{
	t_rgb	clr;

	clr.red = red;
	clr.green = green;
	clr.blue = blue;
	return (clr);
}
