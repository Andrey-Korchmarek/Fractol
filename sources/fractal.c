/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 22:36:37 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 22:36:41 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	fractal(t_fr *chosen)
{
	t_cx	zero;

	zero = (t_cx){0, 0};
	if (chosen->choice == 'm')
		calculate_m(chosen->calc, chosen);
//	else if (chosen->choice == 'j')
//				*chosen->calc = (t_alg){zero, zero, 0, (t_member){zero, 0},
//				j_new, j_next, j_iter};
//	else if (chosen->choice == 'b')
//				*chosen->calc = (t_alg){zero, zero, 0, (t_member){zero, 0},
//				b_new, b_next, b_iter};
	else
		game_over(2);
}

int	iteration(t_alg *data, t_cx (*new)(), void (*next)(), int (*iter)())
{
	(void)iter;
	data->z_n = (t_member){new(data->c, 1), 1};
	while (data->z_n.n < data->maxiter && check(data->z_n.z))
		next(data->c, &data->z_n);
	return (data->z_n.n < data->maxiter ? data->z_n.n * 0x010101 : 0x000000);
}
