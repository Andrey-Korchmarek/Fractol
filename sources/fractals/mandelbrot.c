#include "../../includes/fractol.h"

int	mandelbrot(t_member z)
{
	if (ft_abs_f(z.z.r * z.z.r + z.z.i * z.z.i) > 4)
		return (z.n);
	return (0xFFFFFF);
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
	while (i < maxn && mandelbrot(z[i]) == 0xFFFFFF)
	{
		i++;
		z[i].n = i;
		z[i].z = cx_sum(cx_square(z[i - 1].z), c);
	}
	return ((i == maxn) ? 0xFFFFFF : i);
}