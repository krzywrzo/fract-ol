#ifndef FRACTOL_H
# define FRACTOL_H



# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

/*	WINDOW SIZE	*/
# define WIDTH 800
# define HEIGHT 800

/*	COLORS	*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

/*	FOR MAC COMPILATION	*/
#define KEY_PRESS         2
#define KEY_RELEASE       3
#define BUTTON_PRESS      4
#define BUTTON_RELEASE    5
#define MOTION_NOTIFY     6
#define DESTROY_NOTIFY   17
/*-------------------------*/
typedef struct s_com
{
	double	x;	// real 
	double	y;	// imaginary part
}	t_com;

typedef struct s_img 
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name; 
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	double	escaped_val;
	int		iteration;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	t_img	img;
}	t_fractal;

int	main(int argc, char **argv);

// win_utils.c
void	ft_init_win(t_fractal *fractal);
int 	ft_exit_handler(int keycode, t_fractal *fractal);
void	ft_clean(t_fractal *fractal);

// utils.c 
int		print_error(t_fractal *fractal, t_img *img);
void	free_structs(t_fractal *fractal, t_img *img);
void	error_handler();
void	mandel_vs_julia(t_com *z, t_com *c, t_fractal *fractal);
void	pixel_put(int x, int y, t_img *img, int color);

//	math_utils.c
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_com	sum_com(t_com num, t_com num2);
t_com  sqrt_com(t_com num);
double	atodbl(char *s);

//	fractal_utils.c
void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
void	handle_pixel(int x, int y, t_fractal *fractal);

//	events.c
int key_handler(int key, t_fractal *fractal);
int	mouse_handler(int btn, t_fractal *fractal);
int	julia(int x, int y, t_fractal *fractal);
int close_handler(t_fractal *fractal);

#endif