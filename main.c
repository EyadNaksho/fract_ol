#include "fractol.h"

void	print_usage(void)
{
	write(1, "Usage: ./fractol <fractal_type>\n", 32);
	write(1, "\nAvailable fractals:\n", 20);
	write(1, "  mandelbrot\n", 13);
	write(1, "  julia\n", 8);
}

int	validate_args(int argc, char **argv)
{
	int		i;
	char	*mandelbrot;
	char	*julia;

	if (argc < 2)
		return (0);
	mandelbrot = "mandelbrot";
	julia = "julia";
	i = 0;
	while (mandelbrot[i] && argv[1][i] && mandelbrot[i] == argv[1][i])
		i++;
	if (!mandelbrot[i] && !argv[1][i])
		return (1);
	i = 0;
	while (julia[i] && argv[1][i] && julia[i] == argv[1][i])
		i++;
	if (!julia[i] && !argv[1][i])
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_args(argc, argv))
	{
		print_usage();
		return (1);
	}
	data.fractal_type = argv[1];
	data.min_re = -2.0;
	data.max_re = 1.0;
	data.min_im = -1.5;
	data.max_im = 1.5;
	if (!init_fractal(&data))
	{
		write(2, "Error: Failed to initialize fractal\n", 37);
		return (1);
	}
	render_fractal(&data);
	mlx_loop(data.mlx);
	return (0);
}
