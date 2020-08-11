//
// Created by Mari Ashley on 8/11/20.
//

#include "includes/fractol.h"

t_cx j_new(t_cx k, t_cx c, int n)
{
	t_cx z;

	if (n == 0)
		return (c);
	z = cx_sum(cx_square(j_new(k, c, n - 1)), k);
	return (z);
}