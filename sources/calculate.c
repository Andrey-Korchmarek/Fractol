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

#include "fractol.h"

int	check(t_cx z)
{
	if (z.r * z.r + z.i * z.i <= 4)
		return (1);
	return (0);
}

int	calculate(t_cx c, t_fr *data)
{
	if (data->choice == 'm')
		return (mandelbrot(c, data));
	else if (data->choice == 'j')
		return (julia(c, data));
	else if (data->choice == 'b')
		return (burningship(c, data));
	else
		game_over(2);
	return (0);
}
