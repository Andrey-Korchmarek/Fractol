/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 07:41:22 by mashley           #+#    #+#             */
/*   Updated: 2020/08/13 07:41:25 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship(t_cx c, t_fr *data)
{
	int		n;
	t_cx	z;

	n = 1;
	z = c;
	while (n < data->maxiter && check(z))
	{
		z = cx_sum(cx_square(cx_new(ft_abs_f(z.r), ft_abs_f(z.i))), c);
		n++;
	}
	return (n < data->maxiter ? n : 0);
}
