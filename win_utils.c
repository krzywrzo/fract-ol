/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:43:25 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/17 00:11:56 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_win(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!(fractal->mlx_ptr))
		exit (0);
	fractal->mlx_win_ptr = mlx_new_window(fractal->mlx_ptr, 1080, 1920, fractal->name);
	mlx_hook(fractal->mlx_win_ptr, 2, 1L << 0, ft_exit_handler, fractal);
	mlx_hook(fractal->mlx_win_ptr, 17, 0, ft_exit_handler, fractal);
}

int	ft_exit_handler(int keycode, t_fractal *fractal)
{
	if (keycode == 65307)
		ft_clean(fractal);
	return (1);
}

void	ft_clean(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->mlx_win_ptr);
	// mlx_destroy_display(fractal->mlx_ptr);   // uncomment on linux
	free(fractal->mlx_ptr);
}
