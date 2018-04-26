/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:20:39 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/26 15:01:15 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_inf(t_info *inf)
{
	inf->mlxptr = NULL;
	inf->winptr = NULL;
}

void	init_mandel(t_info *inf)
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
}
