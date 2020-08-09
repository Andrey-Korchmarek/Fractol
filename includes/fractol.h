/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:30:52 by mashley           #+#    #+#             */
/*   Updated: 2020/08/09 17:30:55 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include <stdio.h>
#include <math.h>
#include "../minilibx_macos/mlx.h"

# define ESC	53
#define WIDTH 420
#define HEIGHT 420

typedef struct  s_vars {
	void        *mlx;
	void        *win;
}               t_vars;

typedef	struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef	struct	s_point
{
	int			n;
	double		ca;
	double		cb;
}				t_point;

typedef struct			s_complex
{
	double		r;
	double		i;
}						t_complex;

int				main(void);
int				mandelbrot(t_point point, t_data *data);
int				close(int keycode, t_vars *vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
