/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherkas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:13:41 by bcherkas          #+#    #+#             */
/*   Updated: 2018/05/01 19:08:13 by bcherkas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define MAP_LEN 1240
# define MAX_THREADS 32
# define FRACTAL_NUMBER 6
# define ABS(x) ((x) < 0 ? -(x) : (x))

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
}					t_wrap;

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

typedef struct		s_fun
{
	char			*name;
	void			(*func)();
}					t_fun;

typedef struct		s_info
{
	void			*mlxptr;
	void			*winptr;
	t_image			img;
	t_coord			mlb;
	void			(*draw_func)();
	void			(*wrap_func)();
	t_complex		julia;
	int				fixed;
	t_fun			funcs[FRACTAL_NUMBER];
}					t_info;

void				mandelbrot_wrap(t_info *inf);
void				julia_wrap(t_info *inf);
void				tricorn_wrap(t_info *inf);
void				heart_mandelbrot_wrap(t_info *inf);
void				perp_mandel_wrap(t_info *inf);
void				burn_ship_wrap(t_info *inf);

void				mandelbrot(t_info *inf);
void				julia(t_info *inf);
void				tricorn(t_info *inf);
void				heart_mandelbrot(t_info *inf);
void				perp_mandel(t_info *inf);
void				burn_ship(t_info *inf);

int					mouse_events(int button, int x, int y, void *p);
int					mouse_julia(int x, int y, void *p);

int					triggers(int key, void *elem);
int					triggers2(int key, t_info *inf);
int					escapewindow(t_info *inf);
int					exitwindow(void *elem);

int					dark_red_white(int coef, int max);

void				usage(void);
int					check_if_valid(t_info *inf, char *str);
void				str_to_lower(char *str);
void				fractal_names(void);

#endif
