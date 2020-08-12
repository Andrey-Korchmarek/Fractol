/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:23:04 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 13:23:08 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_cx coord;

	coord = pix_to_coord(&(t_pixel) {x, y, 0}, data->edge, data);
	if (button == 4 || button == 5) {
		if (button == 4)
			zoom(data->zoom, coord, data->edge);
		if (button == 5)
			zoom(1.0 / data->zoom, coord, data->edge);
	}
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}