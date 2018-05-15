/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 18:24:34 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/15 20:18:54 by bcherkas         ###   ########.fr       */
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
	ft_dprintf(2, "Usage: ./fractol \"fractal name\"\n");
	ft_dprintf(2, "\t{bold}Fractal names:\n");
	ft_dprintf(2, "\t-{green}Mandelbrot\n");
	ft_dprintf(2, "\t-{green}Julia\n");
	ft_dprintf(2, "\t-{green}Tricorn\n");
	ft_dprintf(2, "\t-{green}Mandelheart\n");
	ft_dprintf(2, "\t-{green}Perpendicular mandelbrot\n");
	ft_dprintf(2, "\t-{green}Burning ship\n");
	ft_dprintf(2, "\t-{green}Double julia\n");
	ft_dprintf(2, "{bold}There are some key binds");
	ft_dprintf(2, "{bold} that may be useful for you:\n");
	ft_dprintf(2, "{italic}Use \'[\' and \']\' to change fractal\n");
	ft_dprintf(2, "{italic}Use mouse wheel to zoom or reduce image\n");
	ft_dprintf(2, "{italic}Use numbers 1 - 4 to change colors\n");
	ft_dprintf(2, "{italic}Use \'-\' and \'=\' to change color features\n");
	ft_dprintf(2, "{italic}Use \'+\' and \'-\' to");
	ft_dprintf(2, "{italic} change number of iterations\n");
	ft_dprintf(2, "{italic}Use \'f\' to fix position for Julia\n");
	exit(0);
}

void		wrap_help(t_info *inf)
{
	inf->zoom_save = 0;
	inf->mlb.rel_x = (inf->mlb.max_x - inf->mlb.min_x) / (double)(MAP_LEN - 1);
	inf->mlb.rel_y = (inf->mlb.max_y - inf->mlb.min_y) / (double)(MAP_LEN - 1);
	inf->mlb.max_iter = 30;
}
