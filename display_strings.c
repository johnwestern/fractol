/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 04:30:29 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/01 16:36:51 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		display_str2(t_data *e)
{
	if (e->hud == 1)
	{
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 95), 0xFFFFFF, \
			"Use [mouse & clic] to focus on a point");
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 75), 0xFFFFFF, \
			"use arrows to move && use + | - to ajust iter");
		if (e->start == 1)
		{
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 55), 0xFF0000, \
				"Press [R] to restart");
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 35), 0xFFFFFF, \
				"Press [H] to hide this");
		}
		else
			mlx_string_put(e->mlx, e->win, 20, (HGHT - 35), 0x00FF00, \
				"Press [R] if you are ready to explore");
		mlx_string_put(e->mlx, e->win, 20, (HGHT - 115), 0xFFFFFF, \
			"Press [Q] / [A] auto [zoom & iter]");
	}
	else
		mlx_string_put(e->mlx, e->win, 15, (HGHT - 35), 0xFFFF00, "[H]");
}

void			display_str(t_data *e)
{
	if (e->start == 1)
	{
		mlx_string_put(e->mlx, e->win, 20, 10, 0xFFFFFF, "Zoom x");
		mlx_string_put(e->mlx, e->win, 90, 10, 0xFFFFFF, ft_itoa(e->zoom));
		mlx_string_put(e->mlx, e->win, 20, 30, 0xFFFFFF, "Iter =");
		mlx_string_put(e->mlx, e->win, 90, 30, 0xFFFFFF, ft_itoa(e->mitr));
		if (e->mitr <= 390 && e->ato == 1)
			mlx_string_put(e->mlx, e->win, 125, 30, 0x00FF00, "Auto");
		else if (e->mitr > 390)
			mlx_string_put(e->mlx, e->win, 125, 30, 0xF80000, "Max");
	}
	display_str2(e);
	if (e->start == 0)
		mlx_string_put(e->mlx, e->win, (WDH / 10), -10 + (HGHT / 2), \
		0xFFFFFF, "-- MANDELBROT --");
}

void			put_usage_error(char *av)
{
	ft_putstr("Usage1 : ");
	ft_putstr(av);
	ft_putendl(" <fractal_name> mandelbrot || Julia");
	ft_putstr("Usage2 : ");
	ft_putstr(av);
	ft_putendl(" <fractal_name> <fractal_name> mandelbrot || Julia");
	exit(0);
}
