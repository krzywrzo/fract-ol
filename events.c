/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:35:00 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/17 20:11:12 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win_ptr);
	// mlx_destroy_display(fractal->mlx_ptr);	// uncomment on linux
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int key_handler(int key, t_fractal *fractal)
{
	// error because of mac stupid shit
	if (key == 53)									//	Esc
		close_handler(fractal);
	if (key == 123)									//	Left
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (key == 124)							//	Right
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == 126)							//	Up
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (key == 125)							//	Down
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == 47)								//	+ (switched to .)
		fractal->iteration += 10;
	else if (key == 43)								//	- (switched to ,)
		fractal->iteration -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int btn, t_fractal *fractal)
{
	if (btn == 6)								//	scroll down (switched to 6)
		fractal->zoom *= 0.95;
	else if (btn == 7)						//	scroll up (switched to 7)
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
