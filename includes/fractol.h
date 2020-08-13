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
# include "libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"

# define ESC	53
# define MOUSE_UP_SCRLL	0x04
# define MOUSE_DOWN_SCRLL	0x05

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
	int	x;
	int	y;
	int	color;
}				t_pixel;

typedef struct			s_cx
{
	double		r;
	double		i;
}						t_cx;

typedef	struct	s_member
{
	t_cx	z;
	int		n;
}				t_member;

typedef	struct	s_edge
{
	double	minim;
	double	maxim;
	double	minre;
	double	maxre;
}				t_edge;

typedef	struct	s_alg
{
	t_cx		c;
	t_cx		k;
	int			n;
	t_member	z_n;
	int			maxiter;
}				t_alg;

typedef	struct	s_fr
{
	char	choice;
	int		width;
	int		height;
	int		maxiter;
	double	zoom;
	t_cx	k;
	t_image	*img;
	t_edge	*edge;
	t_alg	*calc;

	void	*mlx;
	void	*win;
}				t_fr;

void		game_over(int error);
int			ft_close(int keycode, t_fr *data);
int			mouse_h(int button, int x, int y, t_fr *data);
void		draw(t_fr *data);
void		img_pixel_put(t_image *data, t_pixel *pix);
t_cx		cx_square(t_cx c);
t_cx		cx_sum(t_cx c1, t_cx c2);
t_cx		cx_new(double re, double im);
t_cx		pix_to_coord(t_pixel *pix, t_fr *data);
int			calculate_m(t_alg *alg, t_fr *data);
t_cx		m_new(t_cx c, int n, t_fr *mand);
void		m_next(t_cx c, t_member *z_n);
int			m_iter(void);
int			check(t_cx z);
void		fractal(t_fr *chosen);
int			iteration(t_alg *data, t_cx (*new)(), void (*next)(), int (*iter)());
#endif
