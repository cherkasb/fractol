/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:24:34 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 18:54:51 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			check_if_valid(t_info *inf, char *str)
{
	if (ft_strequ(str, "mandelbrot"))
		inf->wrap_func = mandelbrot_wrap;
	else if (ft_strequ(str, "julia"))
		inf->wrap_func = julia_wrap;
	else if (ft_strequ(str, "tricorn"))
		inf->wrap_func = tricorn_wrap;
	else if (ft_strequ(str, "mandelheart"))
		inf->wrap_func = heart_mandelbrot_wrap;
	else if (ft_strequ(str, "perpendicular mandelbrot"))
		inf->wrap_func = perp_mandel_wrap;
	else if (ft_strequ(str, "burning ship"))
		inf->wrap_func = burn_ship_wrap;
	else
		return (0);
	return (1);
}

void		str_to_lower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

void		fractal_names(void)
{
	ft_dprintf(2, "\t{bold}Fractal names:\n");
	ft_dprintf(2, "\t-{green}Mandelbrot\n");
	ft_dprintf(2, "\t-{green}Julia\n");
	ft_dprintf(2, "\t-{green}Tricorn\n");
	ft_dprintf(2, "\t-{green}Mandelheart\n");
	ft_dprintf(2, "\t-{green}Perpendicular mandelbrot\n");
	ft_dprintf(2, "\t-{green}Burning ship\n");
	exit(0);
}

void		usage(void)
{
	ft_dprintf(2, "Usage: ./fractol \"fractal name\"\n");	
	fractal_names();
}
