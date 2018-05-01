/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:37:17 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 16:51:50 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	move(int key, t_info *inf)
{
	double	el;
	double	y;
	double	x;

	el = ABS((inf->mlb.max_y - inf->mlb.min_y) / 20.0);
	x = 0;
	y = 0;
	if (key == 123)
		x = el;
	else if (key == 124)
		x = -el;
	else if (key == 125)
		y = el;
	else if (key == 126)
		y = -el;
	inf->mlb.max_y += y;
	inf->mlb.min_y += y;
	inf->mlb.max_x += x;
	inf->mlb.min_x += x;
	inf->draw_func(inf);
	return (1);
}

static int	reset(t_info *inf)
{
	inf->wrap_func(inf);
	return (1);
}

static int	change_iter(int key, t_info *inf)
{
	int		i;

	if (key == 78 && inf->mlb.max_iter < 16)
		return (1);
	i = (key == 78) ? -1 : 1;
	inf->mlb.max_iter += i;
	inf->draw_func(inf);
	return (1);
}

static int	fix_pos(t_info *inf)
{
	if (inf->draw_func != julia)
		return (0);
	(inf->fixed)++;
	if (inf->fixed == 2)
		inf->fixed = 0;
	return (1);
}

int			triggers(int key, void *elem)
{
	t_info *inf;

	inf = (t_info *)elem;
	if (key == 53)
		return (escapewindow(inf));
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		return (move(key, inf));
	else if (key == 15)
		return (reset(inf));
	else if (key == 78 || key == 69)
		return (change_iter(key, inf));
	else if (key == 3)
		return (fix_pos(inf));
	else
		return (triggers2(key, inf));
}
