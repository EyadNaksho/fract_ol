#include "fractol.h"

int	is_julia(char *str)
{
	char	*julia;
	int		i;

	julia = "julia";
	i = 0;
	while (julia[i] && str[i] && julia[i] == str[i])
		i++;
	if (!julia[i] && !str[i])
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

double	ft_atof(char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		fraction = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result + (str[i++] - '0') * fraction;
			fraction *= 0.1;
		}
	}
	return (result * sign);
}

void	print_usage(void)
{
	write(1, "Usage: ./fractol <fractal_type> [parameters]\n", 46);
	write(1, "\nAvailable fractals:\n", 21);
	write(1, "  mandelbrot\n", 14);
	write(1, "  julia <real> <imaginary>\n", 28);
	write(1, "  julia (uses default: -0.7 + 0.27015i)\n", 41);
	write(1, "\nJulia examples:\n", 18);
	write(1, "  ./fractol julia\n", 18);
	write(1, "  ./fractol julia -0.7 0.27015\n", 32);
	write(1, "  ./fractol julia 0.285 0.01\n", 30);
	write(1, "  ./fractol julia -0.4 0.6\n", 28);
}

int	validate_args(int argc, char **argv)
{
	int		i;
	char	*mandelbrot;

	if (argc < 2)
		return (0);
	mandelbrot = "mandelbrot";
	i = 0;
	while (mandelbrot[i] && argv[1][i] && mandelbrot[i] == argv[1][i])
		i++;
	if (!mandelbrot[i] && !argv[1][i])
		return (1);
	if (is_julia(argv[1]))
	{
		if (argc == 2 || argc == 4)
		{
			if (argc == 4)
			{
				if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
					return (0);
			}
			return (1);
		}
		return (0);
	}
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
	data.max_re = 2.0;
	data.min_im = -2.0;
	data.max_im = 2.0;
	if (is_julia(argv[1]))
	{
		if (argc == 4)
		{
			data.julia_c.real = ft_atof(argv[2]);
			data.julia_c.imag = ft_atof(argv[3]);
		}
		else
		{
			data.julia_c.real = -0.7;
			data.julia_c.imag = 0.27015;
		}
	}
	if (!init_fractal(&data))
	{
		write(2, "Error: Failed to initialize fractal\n", 37);
		return (1);
	}
	render_fractal(&data);
	mlx_loop(data.mlx);
	return (0);
}
