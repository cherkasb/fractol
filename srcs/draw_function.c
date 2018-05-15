/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:55:12 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/15 21:06:56 by bcherkas         ###   ########.fr       */
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
	pthread_exit(0);
	return (NULL);
}

t_wrap				wrap_init(t_info *inf, int index)
{
	t_wrap	wrap;

	wrap.inf = inf;
	wrap.start = inf->img.img_mass / MAX_THREADS * index;
	wrap.arr = inf->img.img_arr;
	wrap.end = inf->img.img_mass / MAX_THREADS * (index + 1);
	return (wrap);
}

static void			draw_help(t_info *inf)
{
	char	*str;

	mlx_clear_window(inf->mlxptr, inf->winptr);
	mlx_put_image_to_window(inf->mlxptr, inf->winptr, inf->img.img_ptr, 0, 0);
	str = ft_itoa(inf->mlb.max_iter);
	mlx_string_put(inf->mlxptr, inf->winptr, 0, 0, 0xFFFFFF, str);
	ft_strdel(&str);
}

void				draw_function(t_info *inf)
{
	pthread_attr_t	attr;
	t_wrap			wrap[MAX_THREADS];
	pthread_t		th[MAX_THREADS - 1];
	int				index;

	if (inf->color_type == 1)
		inf->mlb.max_iter += 70;
	index = 0;
	pthread_attr_init(&attr);
	while (index < MAX_THREADS)
	{
		wrap[index] = wrap_init(inf, index);
		pthread_create(&(th[index]), &attr, parallel, &(wrap[index]));
		index++;
	}
	index = 0;
	while (index < MAX_THREADS)
	{
		pthread_join(th[index], NULL);
		index++;
	}
	draw_help(inf);
	if (inf->color_type == 1)
		inf->mlb.max_iter -= 70;
}
