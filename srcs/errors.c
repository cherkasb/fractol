/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:24:34 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/28 18:49:14 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		name_error(void)
{
	ft_dprintf(2, "error: {red}Wrong name{reset}\n");  
	ft_dprintf(2, "{green}Tip{reset}: write ");
	ft_dprintf(2, "{bold}\"./fractol names\" ");
	ft_dprintf(2, "to see available fractal names\n");
	exit(0);
}

void		fractal_names(void)
{
	ft_dprintf(2, "\t{bold}Fractal names:\n");
	ft_dprintf(2, "\t-{green}Mandelbrot\n");
	ft_dprintf(2, "\t-{green}Julia\n");
	ft_dprintf(2, "\t-{green}AAA OOOO\n");
	exit(0);
}

void		usage(void)
{
	ft_dprintf(2, "Usage: ./fractol \"fractal name\"\n");	
	fractal_names();
}
