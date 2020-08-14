/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 07:41:50 by mashley           #+#    #+#             */
/*   Updated: 2020/08/13 07:41:53 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cx	cx_square(t_cx c)
{
	double a;
	double b;

	a = c.r;
	b = c.i;
	c.r = (a + b) * (a - b);
	c.i = 2 * a * b;
	return (c);
}

t_cx	cx_sum(t_cx c1, t_cx c2)
{
	t_cx result;

	result.r = c1.r + c2.r;
	result.i = c1.i + c2.i;
	return (result);
}

t_cx	cx_new(double re, double im)
{
	return ((t_cx){re, im});
}
