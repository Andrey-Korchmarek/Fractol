//
// Created by Mari Ashley on 8/13/20.
//

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
	return (n < data->maxiter ? n * 0x010101 : 0);
}