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

t_cx	m_new(t_cx c, int n, t_fr *mand)
{
	t_cx z;

	(void )mand;
	if (n == 0)
		return ((t_cx){0, 0});
	if (n == 1)
		return (c);

	z = cx_sum(cx_square(m_new(c, n - 1, mand)), c);
	return (z);
}

t_member	m_next(t_cx c, t_member z_n)
{
	z_n.z = cx_sum(cx_square(z_n.z), c);
	z_n.n++;
	return (z_n);
}

int	m_iter(void)
{
	return (0);
}
