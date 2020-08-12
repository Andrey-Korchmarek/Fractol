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

typedef	struct	s_edge
{
	double	minim;
	double	maxim;
	double	minre;
	double	maxre;
}				t_edge;

typedef	struct	s_fr
{
	char	choice;
	int		width;
	int		height;
	double	zoom;
	t_edge	*edge;

	void	*mlx;
	void	*win;
}				t_fr;

void	game_over(int error);
int		ft_close(int keycode, t_fr *data);
void	draw(t_fr *data);
void	img_pixel_put(t_image *data, t_pixel *pix);
t_cx	cx_square(t_cx c);
t_cx	cx_sum(t_cx c1, t_cx c2);
t_cx	cx_new(double re, double im);
t_cx	pix_to_coord(t_pixel *pix, t_edge *edge, t_fr *data);
double	interpolate(double start, double end, double paste);
void	zoom(double zoom, t_cx coord, t_edge *ed);

#endif
