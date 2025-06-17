/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:35:00 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/17 14:48:21 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int key_handler(int key, t_fractal *fractal)
{
	// error because of mac stupid shit
	if (key == XK_Escape)
		close_handler(fractal);
	if (key == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (key == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (key == XK_Down)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == XK_Plus)
		fractal->iteration += 10;
	else if (key == XK_Minus)
		fractal->iteration -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int btn, int x, int y, t_fractal *fractal)
{
	if (btn == Button5)
		fractal->zoom *= 0.95;
	else if (btn == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	julia(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
