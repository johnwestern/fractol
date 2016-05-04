/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:07:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/04 21:29:05 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			option1(t_data *e)
{
	e->mouse_x = 0;
	e->mouse_y = 0;
	e->cop = 0;
	e->mitr = 200;
	if (e->opt1 == 0 && (e->zoom = 0.8))
	{
		e->offset_x = -1;
		e->offset_y = 0;
		draw_mandelbrot(e);
	}
	else if (e->opt1 == 1 && (e->zoom = 38.832687))
	{
		e->offset_x = -1.644804;
		e->offset_y = -0.016320;
		draw_burning_ship(e);
	}
	else if (e->opt1 == 2 && (e->zoom = 1))
	{
		e->offset_x = 0;
		e->offset_y = 0;
		draw_julia(e);
	}
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	//mlx_hook(e->win, 6, 3, mouse_hook, e);
}

static void			init1(t_data *e, char *opt)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WDH, HGHT, "Fract\'ol");
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	if (ft_strcmp(opt, "mandelbrot") == 0)
		e->opt1 = 0;
	else if (ft_strcmp(opt, "burningship") == 0)
		e->opt1 = 1;
	else if (ft_strcmp(opt, "julia") == 0)
		e->opt1 = 2;
	else
		put_usage_error("fractol");
	option1(e);
	mlx_loop(e->mlx);
}

int					main(int ac, char **av)
{
	auto t_data		e;

	e.ato = 0;
	e.hud = 1;
	e.start = 0;
	if (ac == 2)
		init1(&e, av[1]);
	else
		put_usage_error(av[0]);
	return (0);
}
