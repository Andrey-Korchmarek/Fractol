#include "../../includes/fractol.h"

int	m_check(t_member *z)
{
	if (ft_abs_f(z->z.r * z->z.r + z->z.i * z->z.i) > 4)
		return (z->n);
	return (0xFFFFFF);
}

t_cx m_next(t_cx z, t_cx c)
{
	return (cx_sum(cx_square(z), c));
}

int iteration(t_cx c, t_cx (*next)(t_cx, t_cx), int (*check)(t_member*))
{
	t_member z_n;

	z_n = (t_member){c, 0};
	if (check(&z_n) != 0xFFFFFF)
		return (z_n.n);
	while (z_n.n++ < 10000 && check(&z_n) == 0xFFFFFF)
		z_n.z = next(z_n.z, c);
	return (z_n.n == 10000 ? 0xFFFFFF : z_n.n);
}

t_cx m_new(t_cx c, int n)
{
	t_cx z;

	if (n == 0)
		return (c);
	z = cx_sum(cx_square(m_new(c, n - 1)), c);
	return (z);
}