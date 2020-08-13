/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 07:43:09 by mashley           #+#    #+#             */
/*   Updated: 2020/08/13 07:43:11 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	julia(t_cx c, t_fr *data)
{
	int		n;
	t_cx	z;

	n = 1;
	z = c;
	while (n < data->maxiter && check(z))
	{
		z = cx_sum(cx_square(z), data->k);
		n++;
	}
	return (n < data->maxiter ? n : 0);
}
