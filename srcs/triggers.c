/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:37:17 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/16 19:49:35 by bcherkas         ###   ########.fr       */
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
	if (key == ARROW_LEFT)
		x = el;
	else if (key == ARROW_RIGHT)
		x = -el;
	else if (key == ARROW_DOWN)
		y = el;
	else if (key == ARROW_UP)
		y = -el;
	inf->mlb.max_y += y;
	inf->mlb.min_y += y;
	inf->mlb.max_x += x;
	inf->mlb.min_x += x;
	draw_function(inf);
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

	if (key == NUMPAD_MIN && inf->mlb.max_iter < 30)
		return (1);
	i = (key == NUMPAD_MIN) ? -5 : 5;
	inf->mlb.max_iter += i;
	draw_function(inf);
	return (1);
}

static int	fix_pos(t_info *inf)
{
	if (inf->draw_func != julia && inf->draw_func != julia_ext)
		return (0);
	inf->fixed = inf->fixed == 1 ? 0 : 1;
	return (1);
}

int			triggers(int key, void *elem)
{
	t_info *inf;

	inf = (t_info *)elem;
	if (key == KEY_ESCAPE)
		return (escapewindow(inf));
	else if (key >= ARROW_LEFT && key <= ARROW_DOWN)
		return (move(key, inf));
	else if (key == KEY_R)
		return (reset(inf));
	else if (key == NUMPAD_PLUS || key == NUMPAD_MIN)
		return (change_iter(key, inf));
	else if (key == KEY_F)
		return (fix_pos(inf));
	else
		return (triggers2(key, inf));
}
