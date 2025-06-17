/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwrzosek <kwrzosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 13:28:10 by kwrzosek          #+#    #+#             */
/*   Updated: 2025/06/17 19:58:19 by kwrzosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int argc, char **argv)
{
	t_fractal	fractal;	// mlx struct

	if (argc == 1)
		return (print_error(&fractal, NULL));
	else if ((!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 2) 
			|| (!ft_strncmp(argv[1], "julia", 5) && argc == 4))
	{
		// TODO 
		// mlx stuff
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractal.julia_x = atodbl(argv[3]);
			fractal.julia_y = atodbl(argv[4]);
		}
		fractal.name = argv[1];
		ft_init_win(&fractal);
		fractal_init(&fractal);
		fractal_render(&fractal);

		mlx_loop(fractal.mlx_ptr);
	}	
	free_structs(&fractal, NULL);
	return (0);
}
