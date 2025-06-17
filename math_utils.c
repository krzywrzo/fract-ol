/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:20:27 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/17 19:58:58 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// linear interpolation
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_com	sum_com(t_com num, t_com num2)
{
	t_com	res;

	res.x = num.x + num2.x;
	res.y = num.y + num2.y;
	return (res);
}

t_com  sqrt_com(t_com num)
{
	t_com	res;

	res.x = (num.x * num.x) - (num.y * num.y);
	res.y = 2 * num.x * num.y;
	return (res);
}

double	atodbl(char *s)
{
	long	i;
	double	f;
	double	pow;
	int		sign;

	i = 0;
	f = 0;
	sign = 1;
	pow = 1;
    if (!s)
        return(0);
    while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign *= -1;
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - 48);
	if ('.' == *s)
		s++;
	while (*s)
	{
		pow /= 10;
		f = f + (*s++ - 48) * pow;
	}
	return ((i + f) * sign);
}
