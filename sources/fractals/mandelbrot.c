#include "../../includes/fractol.h"

int	m_check(t_member *z)
{
	if (ft_abs_f(z->z.r * z->z.r + z->z.i * z->z.i) > 4)
		return (z->n);
	return (0xFFFFFF);
}

t_complex m_next(t_complex z, t_complex c)
{
	return (cx_sum(cx_square(z), c));
}

int iteration(t_complex c, t_complex (*next)(t_complex, t_complex), int (*check)(t_member*))
{
	t_member z_n;

	z_n = (t_member){c, 0};
	while (z_n.n++ < 100 && check(&z_n) == 0xFFFFFF)
		z_n.z = next(z_n.z, c);
	return (z_n.n == 100 ? 0xFFFFFF : z_n.n);
}