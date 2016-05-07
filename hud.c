/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 04:30:29 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/07 02:20:57 by jdavin           ###   ########.fr       */
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
		"Press [Space] to sart exploration");
	if (e->cop == 0)
		mlx_string_put(e->mlx, e->win, 20, 55, 0x0000FF, "   Eclips");
	if (e->cop == 1)
		mlx_string_put(e->mlx, e->win, 20, 55, 0xFFFFFF, "   Black_&_White");
	if (e->cop == 2)
		mlx_string_put(e->mlx, e->win, 20, 55, 0xFF0000, "   Sober_Red");
}

static void		display_str1(t_data *e)
{
	if (e->hud == 1 && WDH > 600 && HGHT > 300)
	{
		
		if (e->st == 1 && WDH > 600 && HGHT > 300)
		{
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 115), 0xFFFFFF, \
				"[Q] = zoom & auto_iter");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 95), 0xFFFFFF, \
				"[mouse & clic] = focus on a point");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 75), 0x00FF00, \
				"[Space] = Restart exploration");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 35), 0xFF0000, \
				"[B] = Back to menu");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 55), 0xF7F700, \
				"[H] = Hide this");
		}
		else
			menu_choose(e);
		
	}
	else
		mlx_string_put(e->mlx, e->win, 10, (HGHT - 30), 0xFFFF00, "[H]");
}

void			display_str(t_data *e)
{
	if (e->st == 1)
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
	if (e->st == 0)
	{
		if (e->opt1 == 0)
			mlx_string_put(e->mlx, e->win, 20, 35, \
			0xFFFFFF, "-> Mandelbrot");
		if (e->opt1 == 1)
			mlx_string_put(e->mlx, e->win, 20, 35, \
			0xFFFFFF, "-> Burning Ship");
		if (e->opt1 == 2)
			mlx_string_put(e->mlx, e->win, 20, 35, \
			0xFFFFFF, "-> Julia");
		mlx_string_put(e->mlx, e->win, 20, 10, 0x00FF00, "[<] change fractal [>]");
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
