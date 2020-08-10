//
// Created by Mari Ashley on 8/10/20.
//

#include "includes/fractol.h"

t_complex	cx_square(t_complex c)
{
	double a;
	double b;

	a = c.r;
	b = c.i;
	c.r = (a + b) * (a - b);
	c.i = 2 * a * b;
	return (c);
}

t_complex	cx_sum(t_complex c1, t_complex c2)
{
	t_complex result;

	result.r = c1.r + c2.r;
	result.i = c1.i + c2.i;
	return (result);
}