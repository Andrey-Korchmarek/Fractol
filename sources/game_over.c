/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:43:20 by mashley           #+#    #+#             */
/*   Updated: 2020/07/18 16:43:24 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	game_over(int error)
{
	if (error == 0)
		ft_putstr("Error!!\n");
	else if (error == 1)
		ft_putstr("usage: fractol  -j for Julia\n"
					"\t\t\t\t-m for Mandelbrot\n"
					"\t\t\t\t-b for Burningship\n");
	else if (error == 2)
		ft_putstr("I don't know what to do :(\n");
	else if (error == 32)
		ft_putstr("!");
	else
		ft_putstr("Some error :(");
	exit(0);
}
