//
// Created by Mari Ashley on 8/13/20.
//

#include "includes/fractol.h"

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
	return (n < data->maxiter ? n * 0x015501 : 0);
}