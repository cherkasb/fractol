/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:00:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 18:49:36 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			thefunc(t_info *inf, t_complex *cpl, int *pixel)
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
		save.im = -2 * ABS(save.re) * save.im + cpl->im;
		save.re = tmp.re - tmp.im + cpl->re;
		n++;
	}
	*pixel = dark_red_white(n, inf->mlb.max_iter);
}

static void			*parallel(void *el)
{
	t_wrap		*wrap;
	t_complex		cpl;
	ssize_t			j;
	ssize_t			i;

	i = 0;
	j = 0;
	wrap = (t_wrap *)el;
	while (wrap->start < wrap->end)
	{
		i = wrap->start / MAP_LEN;
		j = wrap->start % MAP_LEN;
		cpl.im = wrap->inf->mlb.max_y - i * wrap->inf->mlb.rel_y;
		cpl.re = wrap->inf->mlb.min_x + j * wrap->inf->mlb.rel_x;
		thefunc(wrap->inf, &cpl, wrap->arr + wrap->start);
		wrap->start++;
	}
	if (wrap->threaded)
		pthread_exit(0);
	return (NULL);
}

static t_wrap	wrap_init(t_info *inf, int index, int threaded)
{
	t_wrap	wrap;

	wrap.threaded = threaded;
	wrap.inf = inf;
	wrap.start = inf->img.img_mass / MAX_THREADS * index;
	wrap.arr = inf->img.img_arr;
	wrap.end = inf->img.img_mass / MAX_THREADS * (index + 1);
	return (wrap);
}

void				perp_mandel(t_info *inf)
{
	pthread_attr_t	attr;
	t_wrap			wrap[MAX_THREADS];
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
	parallel(&(wrap[index]));
	index = 0;
	while (index < MAX_THREADS - 1)
	{
		pthread_join(th[index],NULL);
		index++;
	}
	mlx_put_image_to_window(inf->mlxptr, inf->winptr, inf->img.img_ptr, 0, 0);
}

void				perp_mandel_wrap(t_info *inf)
{
	inf->draw_func = perp_mandel;
	inf->wrap_func = perp_mandel_wrap;
	inf->mlb.max_x = 1.5;
	inf->mlb.min_x = -2.5;
	inf->mlb.min_y = -2;
	inf->mlb.max_y = inf->mlb.min_y + (inf->mlb.max_x - inf->mlb.min_x);
	inf->mlb.rel_x = (inf->mlb.max_x - inf->mlb.min_x) /
		(double)(MAP_LEN - 1);
	inf->mlb.rel_y = (inf->mlb.max_y - inf->mlb.min_y) /
		(double)(MAP_LEN - 1);
	inf->mlb.max_iter = 30;
	perp_mandel(inf);
}
