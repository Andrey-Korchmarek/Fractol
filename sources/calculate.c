/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:06:44 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 16:06:47 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	check(t_cx z)
{
	if (z.r * z.r + z.i * z.i <= 4)
		return (1);
	return (0);
}

int	calculate_m(t_cx c, t_fr *data)
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
	return (n < data->maxiter ? n * 0x010101 : 0);
}

int	iteration(t_alg *data, t_cx (*new)(), void (*next)(), int (*iter)())
{
	(void)iter;
	data->z_n = get_member(new(data->c, 1), 1);
	while (data->z_n.n < data->maxiter && check(data->z_n.z))
		next(data->c, &data->z_n);
	return (data->z_n.n < data->maxiter ? data->z_n.n * 0x010101 : 0x000000);
}

