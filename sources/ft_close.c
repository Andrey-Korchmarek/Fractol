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

#include "fractol.h"

int		ft_close(int keycode, t_fr *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == KEY_Z)
		iter_change('p', data);
	if (keycode == KEY_X)
		iter_change('m', data);
	return (0);
}

int		mouse_h(int button, int x, int y, t_fr *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_UP_SCRLL || button == MOUSE_DOWN_SCRLL)
	{
		if (button == MOUSE_UP_SCRLL)
		{
			data->zoom *= 1.1;
			data->m_x += ((x - data->width / 2) / data->zoom + data->m_x) -
					((x - data->width / 2) / (data->zoom * 1.1) + data->m_x);
			data->m_y += ((y - data->height / 2) / data->zoom + data->m_y) -
					((y - data->height / 2) / (data->zoom * 1.1) + data->m_y);
		}
		if (button == MOUSE_DOWN_SCRLL)
		{
			data->zoom /= 1.1;
			data->m_x += ((x - data->width / 2) / data->zoom + data->m_x) -
					((x - data->width / 2) / (data->zoom / 1.1) + data->m_x);
			data->m_y += ((y - data->height / 2) / data->zoom + data->m_y) -
					((y - data->height / 2) / (data->zoom / 1.1) + data->m_y);
		}
	}
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}

int		mouse_move(int x, int y, t_fr *data)
{
	data->k = pix_to_coord(&(t_pixel){x, y, 0}, data);
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}

void	iter_change(char key, t_fr *data)
{
	if (data->maxiter < 10 || data->maxiter > 10000)
		return ;
	if (key == 'p')
		data->maxiter += data->step;
	if (key == 'm')
		data->maxiter -= data->step;
	return ;
}
