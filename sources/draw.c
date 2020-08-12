//
// Created by Mari Ashley on 8/11/20.
//

#include "includes/fractol.h"

void	img_pixel_put(t_image *data, t_pixel *pix)
{
	char    *dst;

	dst = data->addr + (pix->y * data->line_length + pix->x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = pix->color;
}

void	img_pixel_full(t_image *img, t_fr *data)
{
	t_pixel pix;
//	t_cx coord;


	pix.y = 0;
	while (pix.y < data->height)
	{
		pix.x = 0;
		while (pix.x < data->width)
		{
			pix.color = iteration(pix_to_coord(pix, data), m_next, m_check);
			img_pixel_put(img, &pix);

			pix.x++;
		}
		pix.y++;
	}
}