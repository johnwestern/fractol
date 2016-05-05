/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 04:30:29 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/05 02:07:28 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		display_str2(t_data *e)
{
	mlx_string_put(e->mlx, e->win, 20, 10, 0xFFFFFF, "Zoom x");
	if (e->zoom > 2000000000)
		mlx_string_put(e->mlx, e->win, 90, 10, 0xFFFFFF, "(2x10^9)++");
	else
		mlx_string_put(e->mlx, e->win, 90, 10, 0xFFFFFF, ft_itoa(e->zoom));
}

static void		menu_choose(t_data *e)
{
	mlx_string_put(e->mlx, e->win, 20, (HGHT - 35), 0x00FF00, \
		"Press [R] if you are ready to explore");
	mlx_string_put(e->mlx, e->win, 20, 10, 0xF6F6F6, \
		"Press [C] to switch color set");
	mlx_string_put(e->mlx, e->win, 65, 30, 0xF6F6F6, \
		"Eclips");
	mlx_string_put(e->mlx, e->win, 65, 50, 0xF6F6F6, \
		"Black & White");
	mlx_string_put(e->mlx, e->win, 65, 70, 0xF6F6F6, \
		"Hell");
	mlx_string_put(e->mlx, e->win, 20, 10, 0xFFFFFF, \
		"Press [C] to switch color set");
	if (e->cop == 0)
		mlx_string_put(e->mlx, e->win, 25, 30, 0xFFFFFF, "- >");
	if (e->cop == 1)
		mlx_string_put(e->mlx, e->win, 25, 50, 0xFFFFFF, "- >");
	if (e->cop == 2)
		mlx_string_put(e->mlx, e->win, 25, 70, 0xFFFFFF, "- >");
}

static void		display_str1(t_data *e)
{
	if (e->hud == 1 && WDH > 1200 && HGHT > 600)
	{
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 115), 0xFFFFFF, \
			"Use [mouse & clic] to focus on a point");
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 95), 0xFFFFFF, \
			"use arrows to move && use + | - to ajust iter");
		if (e->start == 1 && WDH > 1200 && HGHT > 600)
		{
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 75), 0x00FF00, \
				"Press [R] to restart");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 55), 0xFF0000, \
				"Press [B] to got to start menu");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 35), 0xFFFFFF, \
				"Press [H] to hide this");
		}
		else
			menu_choose(e);
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 135), 0xFFFFFF, \
			"Press [Q] / [A] auto [zoom & iter]");
	}
	else
		mlx_string_put(e->mlx, e->win, 15, (HGHT - 35), 0xFFFF00, "[H]");
}

void			display_str(t_data *e)
{
	if (e->start == 1)
	{
		display_str2(e);
		mlx_string_put(e->mlx, e->win, 20, 30, 0xFFFFFF, "Iter =");
		mlx_string_put(e->mlx, e->win, 90, 30, 0xFFFFFF, ft_itoa(e->mitr));
		if (e->mitr <= 594 && e->ato == 1)
			mlx_string_put(e->mlx, e->win, 125, 30, 0x00FF00, "Auto");
		else if (e->mitr > 594)
			mlx_string_put(e->mlx, e->win, 125, 30, 0xF80000, "Max");
	}
	display_str1(e);
	if (e->start == 0)
	{
		if (e->opt1 == 0)
			mlx_string_put(e->mlx, e->win, (WDH / 10), -10 + (HGHT / 2), \
			0xFFFFFF, "-- Mandelbrot --");
		if (e->opt1 == 1)
			mlx_string_put(e->mlx, e->win, (WDH / 4), (HGHT / 6), \
			0xFFFFFF, "-- Burning Ship --");
		if (e->opt1 == 2 && WDH > 1200 && HGHT > 600)
			mlx_string_put(e->mlx, e->win, (WDH - 400), (HGHT - 150), \
			0xFFFFFF, "-- Julia --");
		mlx_string_put(e->mlx, e->win, 1200, (HGHT - 35), 0xFFFFFF, "[<] change fractal [>]");
	}
}

void			put_usage_error(char *av)
{
	ft_putstr("Usage1 : ");
	ft_putstr(av);
	ft_putendl(" <fractal_name> (mandelbrot, bunrningship, Julia)");
	ft_putstr("Usage2 : ");
	ft_putstr(av);
	ft_putendl(" <fractal_name> <fractal_name> \
		(mandelbrot, bunrningship, Julia)");
	exit(0);
}
