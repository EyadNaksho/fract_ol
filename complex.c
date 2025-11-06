/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyadnaksho <eyadnaksho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:38:36 by eyadnaksho        #+#    #+#             */
/*   Updated: 2025/11/05 18:20:00 by eyadnaksho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;
	return (result);
}

t_complex	complex_multiply(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = a.r * b.r - a.i * b.i;
	result.i = a.r * b.i + a.i * b.r;
	return (result);
}

double	complex_abs(t_complex c)
{
	return (sqrt(c.r * c.r + c.i * c.i));
}
