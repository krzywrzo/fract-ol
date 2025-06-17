/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:53:02 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/17 15:38:43 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_structs (t_fractal *fractal, t_img *img)
{
	free(fractal);
	free(img);
}

int	print_error(t_fractal *fractal, t_img *img)
{
	ft_putstr_fd("Error message", STDERR_FILENO);
	free_structs(fractal, img);
	return (1);
}
void	error_handler()
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	mandel_vs_julia(t_com *z, t_com *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}