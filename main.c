/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyadnaksho <eyadnaksho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:37:53 by eyadnaksho        #+#    #+#             */
/*   Updated: 2025/11/05 18:19:54 by eyadnaksho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (!validate_args(argc, argv))
	{
		print_usage();
		return (1);
	}
	init_data(&data, argc, argv);
	if (!init_fractal(&data))
	{
		write(2, "Error: Failed to initialize fractal\n", 37);
		return (1);
	}
	render_fractal(&data);
	mlx_loop(data.mlx);
	return (0);
}
