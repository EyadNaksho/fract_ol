/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyadnaksho <eyadnaksho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:39:35 by eyadnaksho        #+#    #+#             */
/*   Updated: 2025/11/06 00:51:20 by eyadnaksho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800

# define ESC_KEY 65307
# define DESTROY_NOTIFY 17

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define MAX_ITER 150

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		*fractal_type;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	t_complex	julia_c;
}				t_data;

void			print_usage(void);
int				validate_args(int argc, char **argv);
void			init_data(t_data *data, int argc, char **argv);
int				init_fractal(t_data *data);
int				close_window(t_data *data);
int				handle_keypress(int keycode, t_data *data);
int				handle_mouse(int button, int x, int y, t_data *data);
t_complex		complex_add(t_complex a, t_complex b);
t_complex		complex_multiply(t_complex a, t_complex b);
double			complex_abs(t_complex c);
void			render_fractal(t_data *data);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int				get_smooth_color(double nu);
int				get_pixel_color(int iter, double xr, double yi);
int				calc_mandelbrot(t_complex c, double *xr, double *yi);
int				calc_julia(t_complex z, t_complex c, double *xr, double *yi);
double			ft_atof(char *str);
int				is_julia(char *str);
int				is_valid_number(char *str);

#endif
