//
// Created by Mari Ashley on 8/11/20.
//

#include "includes/fractol.h"

int	ft_close(int keycode, t_fr *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int		mouse_h(int button, int x, int y, t_fr *data)
{
//	t_xyab *len;

	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		if (button == 4)
			data->scale -= 10;
		if (button == 5)
			data->scale += 10;
	}
//	mlx_clear_window(data->mlx, data->win);
//	len = (t_xyab*)malloc(sizeof(t_xyab));
//	len-> x = x;
//	len-> y = y;
//	len-> a = 0;
//	len-> b = 0;
//	len-> l = data->height/4;
//	img_pixel_full(data->image, data);
//	free(len);
	return (0);
}