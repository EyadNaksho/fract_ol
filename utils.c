/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyadnaksho <eyadnaksho@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:20:00 by eyadnaksho        #+#    #+#             */
/*   Updated: 2025/11/05 18:19:47 by eyadnaksho       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i++] == '.')
	{
		fraction = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result + (str[i++] - '0') * fraction;
			fraction *= 0.1;
		}
	}
	return (result * sign);
}
