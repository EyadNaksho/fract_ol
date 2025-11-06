/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyadnaksho <eyadnaksho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:37:44 by eyadnaksho        #+#    #+#             */
/*   Updated: 2025/11/06 00:57:54 by eyadnaksho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	calc_mandelbrot(t_complex c, double *xr, double *yi)
{
	int		iter;
	double	xr_new;
	double	yi_new;

	*xr = 0.0;
	*yi = 0.0;
	iter = 0;
	while (*xr * *xr + *yi * *yi <= 4.0 && iter < MAX_ITER)
	{
		xr_new = *xr * *xr - *yi * *yi + c.r;
		yi_new = 2.0 * *xr * *yi + c.i;
		*xr = xr_new;
		*yi = yi_new;
		iter++;
	}
	return (iter);
}

int	calc_julia(t_complex z, t_complex c, double *xr, double *yi)
{
	int		iter;
	double	xr_new;
	double	yi_new;

	*xr = z.r;
	*yi = z.i;
	iter = 0;
	while (*xr * *xr + *yi * *yi <= 4.0 && iter < MAX_ITER)
	{
		xr_new = *xr * *xr - *yi * *yi + c.r;
		yi_new = 2.0 * *xr * *yi + c.i;
		*xr = xr_new;
		*yi = yi_new;
		iter++;
	}
	return (iter);
}

void	render_fractal(t_data *data)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;
	double		coords[2];

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			c.r = data->min_r + (double)x * (data->max_r - data->min_r) / WIDTH;
			c.i = data->min_i + (double)y * (data->max_i - data->min_i)
				/ HEIGHT;
			if (is_julia(data->fractal_type))
				iter = calc_julia(c, data->julia_c, &coords[0], &coords[1]);
			else
				iter = calc_mandelbrot(c, &coords[0], &coords[1]);
			my_mlx_pixel_put(&data->img, x, y, get_pixel_color(iter, coords[0],
					coords[1]));
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
