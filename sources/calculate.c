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

int	calculate_m(t_alg *alg, t_fr *data)
{
	(void)data;
	(void)alg;

	return (0x00FF00);
}

