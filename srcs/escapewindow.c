/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escapewindow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:39:39 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/25 16:49:29 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		escapewindow(t_info *inf)
{
	mlx_destroy_window(inf->mlxptr, inf->winptr);
	exit(1);
	return (0);
}

int		exitwindow(void *elem)
{
	t_info *inf;

	inf = (t_info *)elem;
	mlx_destroy_window(inf->mlxptr, inf->winptr);
	exit(1);
	return (0);
}

