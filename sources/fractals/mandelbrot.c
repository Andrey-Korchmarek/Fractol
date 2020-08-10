#include "../../includes/fractol.h"

int	m_check(t_member z)
{
	if (ft_abs_f(z.z.r * z.z.r + z.z.i * z.z.i) > 4)
		return (z.n);
	return (0xFFFFFF);
}

t_complex m_next(t_complex z, t_complex c)
{
	return (cx_sum(cx_square(z), c));
}

int	mandelbrot2(t_complex c, int maxn)
{
	t_member *z;
	int i;

	if (!(z = (t_member*)malloc(sizeof(t_member) * maxn)))
		game_over(0);
	z[0].n = 0;
	z[0].z.r = 0;
	z[0].z.i = 0;
	i = 0;
	while (i < maxn && m_check(z[i]) == 0xFFFFFF)
	{
		i++;
		z[i].n = i;
		z[i].z = cx_sum(cx_square(z[i - 1].z), c);
	}
	return ((i == maxn) ? 0xFFFFFF : i);
}

int iteration(t_complex c, int (*f)(t_member*))
{
	t_member *z_n;

	*z_n = (t_member){c, 0};
	while (z_n->n++ < 100 && f(z_n) == 0xFFFFFF)

	return (0);
}