/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:00:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/26 19:25:05 by bcherkas         ###   ########.fr       */
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

void		*parallel(void *el)
{
	t_wrapper		*wrap;
	t_info			*inf;
	t_complex		cpl;
	ssize_t			j;

	wrap = (t_wrapper *)el;
	ft_printf("START: %ld\n", wrap->i);
	inf = wrap->inf;
	j = 0;
	while (wrap->i < wrap->max_i)
	{
		cpl.im = inf->mlb.max_y - wrap->i * inf->mlb.rel_x;
		while (j < MAP_LEN)
		{
			cpl.re = inf->mlb.min_x + j * inf->mlb.rel_y;
			thefunc(inf, &cpl, wrap->i, j);
			j++;
		}
		j = 0;
		wrap->i++;
	}
	ft_printf("END: %ld\n", wrap->i);
	if (wrap->threaded)
		pthread_exit(0);
	return (NULL);
}

t_wrapper	wrap_init(t_info *inf, int index, int threaded)
{
	t_wrapper	wrap;

	wrap.threaded = threaded;
	wrap.inf = inf;
	wrap.i = MAP_LEN / MAX_THREADS * index;
	wrap.max_i = MAP_LEN / MAX_THREADS * (index + 1);
	return (wrap);
}

void		mandelbrot(t_info *inf)
{
	pthread_attr_t	attr;
	t_wrapper		wrap[MAX_THREADS];
	pthread_t		th[MAX_THREADS - 1];
	int				index;

	index = 0;
	while (index < MAX_THREADS - 1)
	{
		pthread_attr_init(&attr);
		wrap[index] = wrap_init(inf, index, 1);
		if (pthread_create(&(th[index]), &attr, parallel, &(wrap[index])))
			exit(0);
		index++;
	}
	wrap[MAX_THREADS - 1] = wrap_init(inf, MAX_THREADS - 1, 0);
	parallel(&(wrap[0]));
	index = 0;
	while (index < MAX_THREADS - 1)
	{
		pthread_join(th[index],NULL);
		index++;
	}
}
