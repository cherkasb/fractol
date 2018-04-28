/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:37:17 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/28 19:22:38 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	move(int key, t_info *inf)
{
	double	y;
	double	x;

	x = 0;
	y = 0;
	if (key == 123)
		x = 0.04;
	else if (key == 124)
		x = -0.04;
	else if (key == 125)
		y = 0.04;
	else if (key == 126)
		y = -0.04;
	inf->mlb.max_y += y;
	inf->mlb.min_y += y;
	inf->mlb.max_x += x;
	inf->mlb.min_x += x;
	inf->draw_func(inf);
	return (1);
}

static int	reset(t_info *inf)
{
	inf->mlb.max_x = 1;
	inf->mlb.min_x = -2.0;
	inf->mlb.min_y = -1.2;
	inf->mlb.max_y = inf->mlb.min_y + (inf->mlb.max_x - inf->mlb.min_x);
	inf->mlb.rel_x = (inf->mlb.max_x - inf->mlb.min_x) /
		(double)(MAP_LEN - 1);
	inf->mlb.rel_y = (inf->mlb.max_y - inf->mlb.min_y) /
		(double)(MAP_LEN - 1);
	inf->mlb.max_iter = 30;
	inf->draw_func(inf);
	return (1);
}

static int change_iter(int key, t_info *inf)
{
	int		i;

	if (key == 78 && inf->mlb.max_iter < 16)
		return (1);
	i = (key == 78) ? -1 : 1;
	inf->mlb.max_iter += i;
	inf->draw_func(inf);
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
		change_iter(key, inf);
	return (0);
}
