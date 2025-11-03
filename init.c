#include "fractol.h"

int	close_window(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;
	double	range_re;
	double	range_im;

	if (button == MOUSE_SCROLL_UP)
		zoom_factor = 0.9;
	else if (button == MOUSE_SCROLL_DOWN)
		zoom_factor = 1.1;
	else
		return (0);
	range_re = data->max_re - data->min_re;
	range_im = data->max_im - data->min_im;
	mouse_re = data->min_re + (double)x * range_re / WIDTH;
	mouse_im = data->min_im + (double)y * range_im / HEIGHT;
	data->min_re = mouse_re + (data->min_re - mouse_re) * zoom_factor;
	data->max_re = mouse_re + (data->max_re - mouse_re) * zoom_factor;
	data->min_im = mouse_im + (data->min_im - mouse_im) * zoom_factor;
	data->max_im = mouse_im + (data->max_im - mouse_im) * zoom_factor;
	render_fractal(data);
	return (0);
}

int	init_fractal(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fract'ol");
	if (!data->win)
		return (0);
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
		return (0);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel,
			&data->img.line_length,
			&data->img.endian);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, close_window, data);
	mlx_key_hook(data->win, handle_keypress, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	return (1);
}
