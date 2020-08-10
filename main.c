#include <stdlib.h>
#include "includes/fractol.h"

int	ft_close(int keycode, t_vars *vars)
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

t_complex pix_to_coord(t_pixel pix)
{
	t_complex coord;
	t_complex f = {(2.0 + 2.0) / (400 - 1), (2.0 + 2.0) / (400 - 1)};

	coord.r = - 2 + pix.x * f.r;
	coord.i = 2 - pix.y * f.i;
	return (coord);

}

int main(void)
{
	t_vars	vars;
	t_data	img;
	t_pixel pix;

	vars.mlx = mlx_init();
	img.img = mlx_new_image(vars.mlx, WIDTH, WIDTH);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

	pix.y = 0;
	while (pix.y < HEIGHT)
	{
		pix.x = 0;
		while (pix.x < WIDTH)
		{
			pix.color = mandelbrot2(pix_to_coord(pix), 10);
			my_mlx_pixel_put(&img, pix.x, pix.y, pix.color);
			pix.x++;
		}
		pix.y++;
	}

	vars.win = mlx_new_window(vars.mlx, WIDTH, WIDTH, "Hello world!");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
