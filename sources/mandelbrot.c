/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:18:18 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 22:18:21 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	mandelbrot(t_cx c, t_fr *data)
{
	int		n;
	t_cx	z;

	n = 1;
	z = c;
	while (n < data->maxiter && check(z))
	{
		z = cx_sum(cx_square(z), c);
		n++;
	}
	return (n < data->maxiter ? n : 0);
}
