/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:13:41 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/26 19:47:56 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAP_LEN 1240
# define MAX_THREADS 1

# include "libft.h"
# include "ft_printf.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>

/*
** im - y - width, re - x - lengh
*/

typedef struct		s_wrapper
{
	struct s_info	*inf;
	ssize_t			max_i;
	ssize_t			i;
	int				threaded;
}					t_wrapper;

typedef struct		s_complex
{
	double			im;
	double			re;
}					t_complex;

typedef struct		s_mandelbrot
{
	double			min_y;
	double			max_y;
	double			min_x;
	double			max_x;
	double			rel_x;
	double			rel_y;
	int				max_iter;
}					t_mandelbrot;

typedef struct		s_info
{
	void			*mlxptr;
	void			*winptr;
	t_mandelbrot	mlb;
}					t_info;

void				mandelbrot(t_info *inf);

void				init_inf(t_info *inf);

int					triggers(int key, void *elem);
int					escapewindow(t_info *inf);
int					exitwindow(void *elem);

int					dark_red_white(int coef, int max);

#endif
