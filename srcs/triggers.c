/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triggers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:37:17 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/24 17:43:48 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		triggers(int key, void *elem)
{
	t_info *inf;

	inf = (t_info *)elem;
	if (key == 53)
		return (escapewindow(inf));
	return (0);

}
