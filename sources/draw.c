/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:14:17 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 13:14:21 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pixel_put(t_image *data, t_pixel *pix)
{
	char	*dst;

	dst = data->addr + (pix->y * data->llh + pix->x * (data->bpp / 8));
	*(unsigned int*)dst = pix->color;
}

void	img_pixel_full(t_image *img, t_fr *data)
{
	t_pixel	pix;

	pix.y = 0;
	while (pix.y < data->height)
	{
		pix.x = 0;
		while (pix.x < data->width)
		{
			pix.color = COLOR * calculate(pix_to_coord(&pix, data), data);
			img_pixel_put(img, &pix);
			pix.x++;
		}
		pix.y++;
	}
}

void	draw(t_fr *data)
{
	t_image	img;

	img.img = mlx_new_image(data->mlx, data->width, data->height);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.llh, &img.endian);
	img_pixel_full(&img, data);
	mlx_put_image_to_window(data->mlx, data->win, img.img, 0, 0);
	data->img = &img;
}
