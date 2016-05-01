/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:07:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/01 03:56:20 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init(t_data *e)
{
	e->zoom = 0.80;
	e->offset_x = -1;
	e->offset_y = 0;
	e->mouse_x = 0;
	e->mouse_y = 0;
	e->maxiter = 180;
	e->ato = 0;
	e->hud = 1;
	e->start = 0;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WDH, HGHT, "Fract\'ol");
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	draw_mandelbrot(e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
}

int				main(int ac, char **av)
{
	t_data		e;

	if (ac == 1)
		init(&e);
	else
		put_usage_error(av[0]);
	return (0);
}
