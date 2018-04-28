/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:13:41 by bcherkas          #+#    #+#             */
/*   Updated: 2018/04/28 20:31:59 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAP_LEN 1240
# define MAX_THREADS 8

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
	int				*arr;
	ssize_t			start;
	ssize_t			end;
	int				threaded;
}					t_wrapper;

typedef struct		s_complex
{
	double			im;
	double			re;
}					t_complex;

typedef struct		s_coord
{
	double			min_y;
	double			max_y;
	double			min_x;
	double			max_x;
	double			rel_x;
	double			rel_y;
	int				max_iter;
}					t_coord;

typedef struct		s_image
{
	void			*img_ptr;
	int				*img_arr;
	int				pixel_mass;
	int				line_mass;
	int				img_mass;
	int				endi;
}					t_image;

typedef struct		s_info
{
	void			*mlxptr;
	void			*winptr;
	t_image			img;
	t_coord			mlb;
	void			(*draw_func)();
}					t_info;

void				mandelbrot(t_info *inf);

int					mouse_events(int button, int x, int y, void *p);

int					triggers(int key, void *elem);
int					escapewindow(t_info *inf);
int					exitwindow(void *elem);

int					dark_red_white(int coef, int max);

void				usage(void);
void				name_error(void);
void				fractal_names(void);

#endif
