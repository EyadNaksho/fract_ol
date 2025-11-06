/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyadnaksho <eyadnaksho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:50:00 by eyadnaksho        #+#    #+#             */
/*   Updated: 2025/11/06 00:51:36 by eyadnaksho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_smooth_color(double nu)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = nu / (double)MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_pixel_color(int iter, double xr, double yi)
{
	double	mag;
	double	nu;

	if (iter == MAX_ITER)
		return (0x000000);
	mag = sqrt(xr * xr + yi * yi);
	nu = iter + 1 - log(log(mag)) / log(2.0);
	return (get_smooth_color(nu));
}
