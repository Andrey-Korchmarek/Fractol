//
// Created by Mari Ashley on 8/11/20.
//

#include "includes/fractol.h"

t_cx pix_to_coord(t_pixel pix, t_fr *data)
{
	t_cx coord;
	t_cx f;


	f = cx_new((data->edge->maxre - data->edge->minre) / (WIDTH - 1), (data->edge->maxim - data->edge->minim) / (data->height - 1));
	coord.r = - 2 + pix.x * f.r;
	coord.i = 2 - pix.y * f.i;
	return (coord);
}