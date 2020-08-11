//
// Created by Mari Ashley on 8/11/20.
//

#include "includes/fractol.h"

t_cx pix_to_coord(t_pixel pix, t_fr *data)
{
	t_cx coord;

	coord.r = (pix.x - data->width / 2) / data->scale;
	coord.i = (pix.y - data->height / 2) / data->scale;
	return (coord);
}