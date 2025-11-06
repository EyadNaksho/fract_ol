/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyadnaksho <eyadnaksho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:20:00 by eyadnaksho        #+#    #+#             */
/*   Updated: 2025/11/05 18:19:50 by eyadnaksho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	init_data(t_data *data, int argc, char **argv)
{
	data->fractal_type = argv[1];
	data->min_r = -2.0;
	data->max_r = 2.0;
	data->min_i = -2.0;
	data->max_i = 2.0;
	if (is_julia(argv[1]))
	{
		if (argc == 4)
		{
			data->julia_c.r = ft_atof(argv[2]);
			data->julia_c.i = ft_atof(argv[3]);
		}
		else
		{
			data->julia_c.r = -0.7;
			data->julia_c.i = 0.27015;
		}
	}
}
