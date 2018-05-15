/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headt_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:00:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/15 20:17:09 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				heart_mandelbrot(t_info *inf, t_complex *cpl, int *pixel)
{
	int			n;
	t_complex	save;
	t_complex	tmp;

	save.re = cpl->re;
	save.im = cpl->im;
	n = 0;
	while (n < inf->mlb.max_iter)
	{
		tmp.re = save.re * save.re;
		tmp.im = save.im * save.im;
		if ((tmp.re + tmp.im) > 4)
			break ;
		save.im = 2.0 * ABS(save.re) * save.im + cpl->im;
		save.re = tmp.re - tmp.im + cpl->re;
		n++;
	}
	*pixel = inf->color_func(inf, n, inf->mlb.max_iter);
}

void				heart_mandelbrot_wrap(t_info *inf)
{
	inf->draw_func = heart_mandelbrot;
	inf->wrap_func = heart_mandelbrot_wrap;
	inf->mlb.max_x = 1;
	inf->mlb.min_x = -2.0;
	inf->mlb.min_y = -1.2;
	inf->mlb.max_y = inf->mlb.min_y + (inf->mlb.max_x - inf->mlb.min_x);
	wrap_help(inf);
	draw_function(inf);
}
