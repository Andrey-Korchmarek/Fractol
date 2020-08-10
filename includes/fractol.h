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
#include "libft/includes/libft.h"
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

typedef	struct	s_pixel
{
	int	x;
	int	y;
	int	color;
}				t_pixel;

typedef struct			s_complex
{
	double		r;
	double		i;
}						t_complex;

typedef struct			s_member
{
	t_complex		z;
	int				n;
}						t_member;

typedef	struct	s_sequence
{
	t_complex		z0;
	int				maxn;
	t_complex		c;
}				t_sequence;

int				main(void);
void	game_over(int error);
int				mandelbrot(t_member z);
int				mandelbrot2(t_complex c, int maxn);
int				ft_close(int keycode, t_vars *vars);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_complex		cx_square(t_complex c);
t_complex		cx_sum(t_complex c1, t_complex c2);

#endif
