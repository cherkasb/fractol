/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:58:33 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 19:03:50 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_zoom(int button, int x, int y, t_info *inf)
{
	static int	save;
	double		zoom;
	t_coord		*mlb;
	double		ms_re;
	double		ms_im;

	if ((save == 295 && button == 5) || (save == -10 && button == 4))
		return (0);
	save += (button == 4) ? -1 : 1;
	zoom = (button == 4) ? 1.1 : 0.9;
	mlb = &(inf->mlb);
	ms_re = inf->mlb.min_x + (double)x * inf->mlb.rel_x;
	ms_im = inf->mlb.max_y - (double)y * inf->mlb.rel_y;
	mlb->max_x = ms_re + ((mlb->max_x - ms_re) * zoom);
	mlb->min_x = ms_re + ((mlb->min_x - ms_re) * zoom);
	mlb->max_y = ms_im + ((mlb->max_y - ms_im) * zoom);
	mlb->min_y = ms_im + ((mlb->min_y - ms_im) * zoom);
	mlb->rel_x = (mlb->max_x - mlb->min_x) / (double)(MAP_LEN - 1);
	mlb->rel_y = (mlb->max_y - mlb->min_y) / (double)(MAP_LEN - 1);
	mlb->max_iter += (save % 10 && button == 5) ? 1 : 0;
	mlb->max_iter += (save % 10 && button == 4) ? -1 : 0;
	inf->draw_func(inf);
	return (1);
}

int		mouse_julia(int x, int y, void *p)
{
	t_complex	*jul;
	t_info 		*inf;

	inf = (t_info *)p;
	if (inf->draw_func != julia || inf->fixed == 1)
		return (0);
	jul = &inf->julia;
	jul->im = inf->mlb.max_y - y * inf->mlb.rel_y;
	jul->re = inf->mlb.max_x - x * inf->mlb.rel_x;
	julia(inf);
	return (1);
}

int		mouse_events(int button, int x, int y, void *p)
{
	t_info	*inf;

	inf = (t_info *)p;
	if (button == 4 || button == 5)
		return (mouse_zoom(button, x, y, inf));
	return (0);
}
