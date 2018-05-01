/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:37:17 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 19:00:37 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	change_func(int key, t_info *inf)
{
	int		i;

	i = 0;
	while (inf->funcs[i].func != inf->wrap_func && i < FRACTAL_NUMBER)
		i++;
	i += key == 33 ? -1 : 1;
	if (i < 0)
		i = FRACTAL_NUMBER - 1;
	else if (i >= FRACTAL_NUMBER)
		i = 0;
	inf->funcs[i].func(inf);
	return (1);
}

int			triggers2(int key, t_info *inf)
{
	if (key == 33 || key == 30)
		return (change_func(key, inf));
	return (0);
}
