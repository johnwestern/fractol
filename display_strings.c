/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 04:30:29 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/06 16:06:57 by jdavin           ###   ########.fr       */
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
		"Press [Space] if you are ready to explore");
	if (e->cop == 0)
		mlx_string_put(e->mlx, e->win, 20, 55, 0xFFFFFF, "-> Eclips");
	if (e->cop == 1)
		mlx_string_put(e->mlx, e->win, 20, 55, 0xFFFFFF, "-> Black_&_White");
	if (e->cop == 2)
		mlx_string_put(e->mlx, e->win, 20, 55, 0xFFFFFF, "-> Sober_Red");
}

static void		display_str1(t_data *e)
{
	if (e->hud == 1 && WDH > 1200 && HGHT > 600)
	{
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 115), 0xFFFFFF, \
			"Use [mouse & clic] = focus on a point");
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 95), 0xFFFFFF, \
			"use arrows to move && use + | - = ajust iter");
		if (e->start == 1 && WDH > 1200 && HGHT > 600)
		{
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 75), 0x00FF00, \
				"Press [Space] = restart");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 55), 0xFF0000, \
				"Press [B] = get back to start menu");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 35), 0xFFFFFF, \
				"Press [H] = hide this");
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
			mlx_string_put(e->mlx, e->win, 20, 35, \
			0xFFFFFF, "-> Mandelbrot");
		if (e->opt1 == 1)
			mlx_string_put(e->mlx, e->win, 20, 35, \
			0xFFFFFF, "-> Burning Ship");
		if (e->opt1 == 2 && WDH > 1200 && HGHT > 600)
			mlx_string_put(e->mlx, e->win, 20, 35, \
			0xFFFFFF, "-> Julia");
		mlx_string_put(e->mlx, e->win, 20, 10, 0xFFFFFF, "[<] change fractal [>]");
	}
}

void			put_usage_error(char *av)
{
	ft_putstr("Usage : ./");
	ft_putstr(av);
	ft_putendl(" <fractalias>\n\
	\nfractalias:\nm = mandelbrot\nb = burningship\nj = julia");
	exit(0);
}
