/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 19:58:33 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/28 20:39:00 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_zoom(int button, int x, int y, t_info *inf)
{
	double		zoom;
	t_coord		*mlb;
	double		ms_re;
	double		ms_im;

	zoom = (button == 4) ? 1.0 / 1.03 : 1.03;
	mlb = &(inf->mlb);
	ms_re = (double)x / (MAP_LEN / (mlb->max_x - mlb->min_x)) + mlb->min_x;
	ms_im = (double)y / (MAP_LEN / (mlb->max_y - mlb->min_y)) + mlb->min_y;
	mlb->max_x = ms_re + ((mlb->max_x - ms_re) * zoom);
	mlb->min_x = ms_re + ((mlb->min_x - ms_re) * zoom);
	mlb->max_y = ms_re + ((mlb->max_y - ms_re) * zoom);
	mlb->min_y = ms_re + ((mlb->min_y - ms_re) * zoom);
	inf->draw_func(inf);
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
