#include <stdlib.h>
#include "includes/fractol.h"

int	close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	t_vars	vars;
	t_data	img;
	int		x;
	int		y;
	t_point	point;

	vars.mlx = mlx_init();
	img.img = mlx_new_image(vars.mlx, WIDTH, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	point.n = 100;
	point.ca = 2.0;
	while (point.ca >= -2.0)
	{
		point.cb = 2.0;
		while (point.cb >= -2.0)
		{
			my_mlx_pixel_put(&img, (int)(point.cb * 100), (int)(point.ca * 100), mandelbrot(point, NULL));
			point.cb -= 0.01;
		}
		point.ca -= 0.01;
	}
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}

	vars.win = mlx_new_window(vars.mlx, WIDTH, WIDTH, "Hello world!");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
