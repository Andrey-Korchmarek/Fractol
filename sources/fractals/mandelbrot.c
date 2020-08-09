#include "../../includes/fractol.h"

int	mandelbrot(t_point point, t_data *data)
{
	int			i;
	double		za;
	double		zb;
	double		tmp;
	t_complex	c;

	(void)data;
	za = 0;
	zb = 0;
	i = 0;
	while (za * za + zb * zb <= 4 && i < point.n)
	{
		tmp = za;
		za = tmp * tmp - zb * zb + point.ca;
		zb = 2 * tmp * zb + point.cb;
		i++;
	}
	c.r = za;
	c.i = zb;
	if (i == point.n)
		return (0);
	else
		return ((unsigned int)i);
}