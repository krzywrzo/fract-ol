/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:47:28 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/17 20:09:45 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//	LINUX VERSION
// void	events_init(t_fractal *fractal)
// {
// 	mlx_hook(fractal->mlx_win_ptr, KeyPress, KeyPressMask, key_handler, fractal);
// 	mlx_hook(fractal->mlx_win_ptr, ButtonPress, ButtonPressMask, mouse_handler, fractal);
// 	mlx_hook(fractal->mlx_win_ptr, DestroyNotify, StructureNotifyMask, close_handler, fractal);
// 	mlx_hook(fractal->mlx_win_ptr, MotionNotify, PointerMotionMask, julia, fractal);
// }

//	MAC VERSION
void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win_ptr, KEY_PRESS, 0, key_handler, fractal);
	mlx_hook(fractal->mlx_win_ptr, BUTTON_PRESS, 0, mouse_handler, fractal);
	mlx_hook(fractal->mlx_win_ptr, DESTROY_NOTIFY, 0, close_handler, fractal);
	mlx_hook(fractal->mlx_win_ptr, MOTION_NOTIFY, 0, julia, fractal);
}
void	data_init(t_fractal *fractal)
{
	fractal->escaped_val = 4;
	fractal->iteration = 42;	// starting iteration value
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		error_handler();
	fractal->mlx_win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_win_ptr == NULL)
		error_handler();
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win_ptr);
		// mlx_destroy_display(fractal->mlx_ptr);	// uncomment on linux
		free(fractal->mlx_ptr);
		error_handler();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp,
											 &fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);	
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_com	z;
	t_com	c;
	int		i;
	int		color;

	i = 0;
	z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iteration)
	{
		z = sum_com(sqrt_com(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escaped_val)
		{
			color = map(i, BLACK, WHITE, 0, fractal->iteration);
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	pixel_put(x, y, &fractal->img, WHITE);	//	TODO
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->mlx_win_ptr, fractal->img.img_ptr, 0, 0);
}
