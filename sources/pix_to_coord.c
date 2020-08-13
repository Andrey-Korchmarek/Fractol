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

t_cx	pix_to_coord(t_pixel *pix, t_fr *data)
{
	t_cx	coord;

	coord.r = (pix->x - data->width / 2) / data->zoom + data->m_x;
	coord.i = (pix->y - data->height / 2) / data->zoom + data->m_y;
	return (coord);
}
