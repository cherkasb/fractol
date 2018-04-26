/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:00:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/26 15:02:08 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	thefunc(t_info *inf, t_complex *cpl, size_t i, size_t j)
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
		save.im = 2 * save.re * save.im + cpl->im;
		save.re = tmp.re - tmp.im + cpl->re;
		n++;
	}
//	printf("X: %zd, Y: %zd, inside: %d\n, re: %g, im: %g\n", i, j, is_inside, cpl->re, cpl->im);
	mlx_pixel_put(inf->mlxptr, inf->winptr, j, i, dark_red_white(n , inf->mlb.max_iter));
}

void		parallel(t_info *inf, ssize_t j)
{
	t_complex		cpl;
	ssize_t			i;
	ssize_t			j;

	i = 0;
	j = 0;
	while (i < MAP_LEN)
	{
		cpl.im = inf->mlb.max_y - i * inf->mlb.rel_x;
		while (j < MAP_LEN)
		{
			cpl.re = inf->mlb.min_x + j * inf->mlb.rel_y;
			thefunc(inf, &cpl, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	mandelbrot(t_info *inf)
{
	ssize_t	i;

	i = 0;
}
