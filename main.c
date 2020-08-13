/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:32:15 by mashley           #+#    #+#             */
/*   Updated: 2020/08/12 09:32:18 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	set_default(t_fr *data)
{
	t_edge ed;
	t_cx	zero;

	zero = (t_cx){0, 0};
	data->width = 800;
	data->height = 800;
		data->maxiter = 100;
	data->zoom = 150;
	data->img = NULL;
	ed = (t_edge){-2.0, 2.0, -2.0, 2.0};
	ed.maxre = (ed.maxim - ed.minim) * (data->width * 1.0 / data->height) +
			   ed.minre;
	data->edge = &ed;
	*data->calc = (t_alg){zero, zero, 0, (t_member){zero, 0}, data->maxiter};
	data->mlx = mlx_init();
	data->win =\
		mlx_new_window(data->mlx, data->width, data->height, "Fractol");
}

int	main(int argc, char **argv)
{
	t_fr	*main;

	main = (t_fr*)malloc(sizeof(t_fr));
	if (argc != 2)
		game_over(1);
	if (argc == 2)
		main->choice = argv[1][1];
	set_default(main);
	draw(main);

	mlx_key_hook(main->win, ft_close, main);
	mlx_mouse_hook(main->win, mouse_h, main);
	mlx_loop(main->mlx);
	free(main);
	return (0);
}
