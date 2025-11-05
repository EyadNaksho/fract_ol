#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter, int max_iter)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iter == max_iter)
		return (0x000000);
	t = (double)iter / (double)max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	mandelbrot_iter(t_complex c)
{
	t_complex	z;
	t_complex	temp;
	int			iter;
	double		z_real_sq;
	double		z_imag_sq;

	z.real = 0;
	z.imag = 0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		z_real_sq = z.real * z.real;
		z_imag_sq = z.imag * z.imag;
		if (z_real_sq + z_imag_sq > 4.0)
			break ;
		temp.real = z_real_sq - z_imag_sq + c.real;
		temp.imag = 2.0 * z.real * z.imag + c.imag;
		z = temp;
		iter++;
	}
	return (iter);
}

int	julia_iter(t_complex z, t_complex c)
{
	t_complex	temp;
	int			iter;
	double		z_real_sq;
	double		z_imag_sq;

	iter = 0;
	while (iter < MAX_ITER)
	{
		z_real_sq = z.real * z.real;
		z_imag_sq = z.imag * z.imag;
		if (z_real_sq + z_imag_sq > 4.0)
			break ;
		temp.real = z_real_sq - z_imag_sq + c.real;
		temp.imag = 2.0 * z.real * z.imag + c.imag;
		z = temp;
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
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = data->min_re + (double)x * (data->max_re - data->min_re) / WIDTH;
			c.imag = data->min_im + (double)y * (data->max_im - data->min_im) / HEIGHT;
			if (is_julia(data->fractal_type))
				iter = julia_iter(c, data->julia_c);
			else
				iter = mandelbrot_iter(c);
			color = get_color(iter, MAX_ITER);
			my_mlx_pixel_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
