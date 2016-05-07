/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:07:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/07 23:56:41 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			fract_init(t_data *e)
{
	if (e->opt1 == 0 && (e->zoom = 0.85))
	{
		e->offset_x = -0.75;
		draw_mandelbrot(e);
	}
	else if (e->opt1 == 1 && (e->zoom = 38.832687))
	{
		e->offset_x = -1.644804;
		e->offset_y = -0.016320;
		draw_burning_ship(e);
	}
	else if (e->opt1 == 2 && (e->zoom = 0.8))
		draw_julia(e);
	else if (e->opt1 == 3 && (e->zoom = 1.1))
		draw_glynn(e);
	else if (e->opt1 == 4 && (e->zoom = 0.6))
		draw_newton(e);
}

void				option1(t_data *e)
{
	e->mouse_x = 0;
	e->mouse_y = 0;
	e->motion_x = 0;
	e->motion_y = 0;
	e->offset_x = 0;
	e->offset_y = 0;
	e->mitr = 150;
	fract_init(e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, 6, 1L << 6, motion_hook, e);
}

static void			init1(t_data *e, char *opt)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WDH, HGHT, "Fract\'ol");
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	if (ft_strcmp(opt, "0") == 0 || ft_strcmp(opt, "mandelbrot") == 0)
		e->opt1 = 0;
	else if (ft_strcmp(opt, "1") == 0 || ft_strcmp(opt, "burningship") == 0)
		e->opt1 = 1;
	else if (ft_strcmp(opt, "2") == 0 || ft_strcmp(opt, "julia") == 0)
		e->opt1 = 2;
	else if (ft_strcmp(opt, "3") == 0 || ft_strcmp(opt, "glynn") == 0)
		e->opt1 = 3;
	else if (ft_strcmp(opt, "4") == 0 || ft_strcmp(opt, "newton") == 0)
		e->opt1 = 4;
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
	e.st = 0;
	e.cop = 0;
	if (ac == 2)
		init1(&e, av[1]);
	else
		put_usage_error("fractol");
	return (0);
}
