/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:00:22 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/28 20:32:55 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	thefunc(t_info *inf, t_complex *cpl, int *pixel)
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
	*pixel = dark_red_white(n, inf->mlb.max_iter);
}

void		*parallel(void *el)
{
	t_wrapper		*wrap;
	t_complex		cpl;
	ssize_t			j;
	ssize_t			i;

	i = 0;
	j = 0;
	wrap = (t_wrapper *)el;
	while (wrap->start < wrap->end)
	{
		i = wrap->start / MAP_LEN;
		j = wrap->start % MAP_LEN;
		cpl.im = wrap->inf->mlb.max_y - i * wrap->inf->mlb.rel_x;
		cpl.re = wrap->inf->mlb.min_x + j * wrap->inf->mlb.rel_y;
		thefunc(wrap->inf, &cpl, wrap->arr + wrap->start);
		wrap->start++;
	}
	if (wrap->threaded)
		pthread_exit(0);
	return (NULL);
}

t_wrapper	wrap_init(t_info *inf, int index, int threaded)
{
	t_wrapper	wrap;

	wrap.threaded = threaded;
	wrap.inf = inf;
	wrap.start = inf->img.img_mass / MAX_THREADS * index;
	wrap.arr = inf->img.img_arr;
	wrap.end = inf->img.img_mass / MAX_THREADS * (index + 1);
	return (wrap);
}

void		mandelbrot(t_info *inf)
{
	pthread_attr_t	attr;
	t_wrapper		wrap[MAX_THREADS];
	pthread_t		th[MAX_THREADS - 1];
	int				index;

	inf->draw_func = mandelbrot;
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
