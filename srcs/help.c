/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:24:34 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/16 19:45:32 by bcherkas         ###   ########.fr       */
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
	else if (ft_strequ(str, "double julia"))
		inf->wrap_func = julia_ext_wrap;
	else if (ft_strequ(str, "celtic"))
		inf->wrap_func = celtic_wrap;
	else
		return (0);
	return (1);
}

void		str_to_lower(char **str)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (str[i])
	{
		while (str[i][j])
		{
			str[i][j] = ft_tolower(str[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
}

void		usage(void)
{
	ft_printf("Usage: ./fractol \"fractal name\"\n");
	ft_printf("\t{bold}Fractal names:\n");
	ft_printf("\t-{green}Mandelbrot\n");
	ft_printf("\t-{green}Julia\n");
	ft_printf("\t-{green}Tricorn\n");
	ft_printf("\t-{green}Mandelheart\n");
	ft_printf("\t-{green}Perpendicular mandelbrot\n");
	ft_printf("\t-{green}Burning ship\n");
	ft_printf("\t-{green}Double julia\n");
	ft_printf("\t-{green}Celtic\n");
	ft_printf("{bold}There are some key binds");
	ft_printf("{bold} that may be useful for you:\n");
	ft_printf("{italic}Use \'[\' and \']\' to change fractal\n");
	ft_printf("{italic}Use mouse wheel to zoom or reduce image\n");
	ft_printf("{italic}Use numbers 1 - 6 to change colors\n");
	ft_printf("{italic}Use \'-\' and \'=\' to change color features\n");
	ft_printf("{italic}Use \'+\' and \'-\' to");
	ft_printf("{italic} change number of iterations\n");
	ft_printf("{italic}Use \'f\' to fix position for Julia\n");
	exit(0);
}

void		wrap_help(t_info *inf)
{
	inf->zoom_save = 0;
	inf->mlb.rel_x = (inf->mlb.max_x - inf->mlb.min_x) / (double)(MAP_LEN - 1);
	inf->mlb.rel_y = (inf->mlb.max_y - inf->mlb.min_y) / (double)(MAP_LEN - 1);
	inf->mlb.max_iter = 30;
}
