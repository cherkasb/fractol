/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:55:12 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/02 17:12:21 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				*parallel(void *el)
{
	t_wrap			*wrap;
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
		wrap->inf->draw_func(wrap->inf, &cpl, wrap->arr + wrap->start);
		wrap->start++;
	}
	if (wrap->threaded)
		pthread_exit(0);
	return (NULL);
}

t_wrap				wrap_init(t_info *inf, int index, int threaded)
{
	t_wrap	wrap;

	wrap.threaded = threaded;
	wrap.inf = inf;
	wrap.start = inf->img.img_mass / MAX_THREADS * index;
	wrap.arr = inf->img.img_arr;
	wrap.end = inf->img.img_mass / MAX_THREADS * (index + 1);
	return (wrap);
}

void				draw_function(t_info *inf)
{
	pthread_attr_t	attr;
	t_wrap			wrap[MAX_THREADS];
	pthread_t		th[MAX_THREADS - 1];
	int				index;

	index = 0;
	pthread_attr_init(&attr);
	while (index < MAX_THREADS - 1)
	{
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
