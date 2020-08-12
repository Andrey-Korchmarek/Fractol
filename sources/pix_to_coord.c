/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix_to_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:20:58 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 13:21:02 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

t_cx	pix_to_coord(t_pixel *pix, t_edge *edge, t_fr *data)
{
	t_cx coord;
	t_cx f;

	f = cx_new((edge->maxre - edge->minre) / (data->width - 1),
			(edge->maxim - edge->minim) / (data->height - 1));
	coord.r = edge->minre + pix->x * f.r;
	coord.i = edge->maxim - pix->y * f.i;
	return (coord);
}

double	interpolate(double start, double end, double paste)
{
	return (start + ((end - start) * paste));
}

void zoom(double zoom, t_cx coord, t_edge *ed)
{
	ed->minre = interpolate(coord.r, ed->minre, zoom);
	ed->minim = interpolate(coord.i, ed->minim , zoom);
	ed->maxre = interpolate(coord.r, ed->maxre, zoom);
	ed->maxim = interpolate(coord.i, ed->maxim, zoom);
}
