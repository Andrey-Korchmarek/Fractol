/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 05:56:02 by mashley           #+#    #+#             */
/*   Updated: 2020/08/11 05:56:07 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void set_default(t_fr *data)
{
	data->width = 800;
	data->height = 800;
	data->scale = 350;
	data->mlx = mlx_init();
	data->win =\
		mlx_new_window(data->mlx, data->width, data->height, "Fractol");
}

int	main(void)
{
	t_fr	*data;
	t_image *img;

	if (!(data = (t_fr*)malloc(sizeof(t_fr))))
		return (0);
//	if (argc == 2)
//		data->choice = argv[1][1];
	set_default(data);
	if (!(img = (t_image*)malloc(sizeof(t_image))))
		return (0);
	img->img = mlx_new_image(data->mlx, data->width, data->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	t_xyab *len = (t_xyab*)malloc(sizeof(t_xyab));
	len-> x = data->width/2;
	len-> y = data->height/2;
	len-> a = 0;
	len-> b = 0;
	len-> l = data->height/4;
	data->len = len;
	img_pixel_full(img, data, len);
	data->image = img;
	mlx_key_hook(data->win, ft_close, data);
	mlx_loop(data->mlx);
	return (0);
}
