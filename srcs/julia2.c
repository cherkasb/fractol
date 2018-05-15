/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:00:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/15 20:15:51 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			julia_ext(t_info *inf, t_complex *cpl, int *pixel)
{
	int			n;
	t_complex	save;
	t_complex	tmp;
	t_complex	sqr;

	save.re = cpl->re;
	save.im = cpl->im;
	n = 0;
	while (n < inf->mlb.max_iter)
	{
		tmp.re = save.re * save.re;
		tmp.im = save.im * save.im;
		sqr.re = tmp.re * tmp.re;
		sqr.im = tmp.im * tmp.im;
		if ((tmp.re + tmp.im) > 4)
			break ;
		save.im = save.im * (5 * sqr.re - 10 * (tmp.re * tmp.im) + sqr.im)
			+ inf->julia.im;
		save.re = save.re * (sqr.re - 10 * (tmp.re * tmp.im) + 5 * sqr.im)
			+ inf->julia.re;
		n++;
	}
	*pixel = inf->color_func(inf, n, inf->mlb.max_iter);
}

void			julia_ext_wrap(t_info *inf)
{
	inf->fixed = 0;
	inf->julia.im = 0.288;
	inf->julia.re = 0.353;
	inf->draw_func = julia_ext;
	inf->wrap_func = julia_ext_wrap;
	inf->mlb.max_x = 1.8;
	inf->mlb.min_x = -1.8;
	inf->mlb.min_y = -1.8;
	inf->mlb.max_y = inf->mlb.min_y + (inf->mlb.max_x - inf->mlb.min_x);
	wrap_help(inf);
	draw_function(inf);
}
