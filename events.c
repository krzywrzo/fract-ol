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
	mlx_destroy_display(fractal->mlx_ptr);	// uncomment on linux
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int key_handler(int key, t_fractal *fractal)
{
	// error because of mac stupid shit
	if (key == XK_Escape)									//	Esc -> XK_Escape -> 53
		close_handler(fractal);
	if (key == XK_Left)									//	Left -> XK_Left -> 123 
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (key == XK_Right)							//	Right -> XK_Right -> 124
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (key == XK_Up)							//	Up -> XK_Up -> 126
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (key == XK_Down)							//	Down -> XK_Down -> 125
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (key == XK_m)								//	+ (switched to m) -> XK_m 
		fractal->iteration += 10;
	else if (key == XK_h)								//	- (switched to h) -> XK_h
		fractal->iteration -= 10;
    fractal_render(fractal);
    return (0);
}

int	mouse_handler(int btn, int x, int y, t_fractal *fractal)
{
    (void)x;
    (void)y;

    if (btn == Button5)								//	scroll down (switched to z)
		fractal->zoom *= 0.95;
	else if (btn == Button4)						//	scroll up (switched to x)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

int	julia(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
        (void)x;
        (void)y;
//		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
//		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
        fractal_render(fractal);
	}
	return (0);
}
