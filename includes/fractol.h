/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:31:58 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 09:32:02 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "../minilibx_macos/mlx.h"

# define ESC 53
# define KEY_Z 6
# define KEY_X 7
# define MOUSE_UP_SCRLL 0x04
# define MOUSE_DOWN_SCRLL 0x05
# define COLOR 0x654321

typedef	struct	s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			llh;
	int			endian;
}				t_image;

typedef	struct	s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_cx
{
	double		r;
	double		i;
}				t_cx;

typedef	struct	s_edge
{
	double		minim;
	double		maxim;
	double		minre;
	double		maxre;
}				t_edge;

typedef	struct	s_fr
{
	char		choice;
	int			width;
	int			height;
	int			maxiter;
	int			step;
	double		zoom;
	double		m_x;
	double		m_y;
	t_cx		c;
	t_cx		k;
	t_image		*img;
	t_edge		*edge;

	void		*mlx;
	void		*win;
}				t_fr;

void			game_over(int error);
int				ft_close(int keycode, t_fr *data);
int				mouse_h(int button, int x, int y, t_fr *data);
void			draw(t_fr *data);
void			img_pixel_put(t_image *data, t_pixel *pix);
t_cx			cx_square(t_cx c);
t_cx			cx_sum(t_cx c1, t_cx c2);
t_cx			cx_new(double re, double im);
t_cx			pix_to_coord(t_pixel *pix, t_fr *data);
int				calculate(t_cx c, t_fr *data);
int				mandelbrot(t_cx c, t_fr *data);
int				julia(t_cx c, t_fr *data);
int				burningship(t_cx c, t_fr *data);
int				check(t_cx z);
int				mouse_move(int x, int y, t_fr *data);
void			iter_change(char key, t_fr *data);

#endif
