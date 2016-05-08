/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:35:37 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/08 13:24:32 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int			motion_hook(int x, int y, t_data *e)
{
	if (x < WDH && x > 0 && y < HGHT && y > 0 && e->st == 0)
	{
		e->motion_x = 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / \
		e->zoom;
		e->motion_y = (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom;
	}
	draw_option(e);
	return (0);
}

void		fractal_switch(int key, t_data *e)
{
	if (key == 123)
	{
		if (e->opt1 > 0)
			e->opt1 -= 1;
		else
			e->opt1 = 6;
	}
	if (key == 124)
	{
		if (e->opt1 < 6)
			e->opt1 += 1;
		else
			e->opt1 = 0;
	}
	option1(e);
}

void		fractal_name(t_data *e)
{
	if (e->opt1 == 0)
		mlx_string_put(e->mlx, e->win, 20, 35, 0xFFFFFF, "-> Mandelbrot");
	else if (e->opt1 == 3)
		mlx_string_put(e->mlx, e->win, 20, 35, 0xFFFFFF, "-> Burning Ship");
	else if (e->opt1 == 1)
		mlx_string_put(e->mlx, e->win, 20, 35, 0xFFFFFF, "-> Julia");
	else if (e->opt1 == 2)
		mlx_string_put(e->mlx, e->win, 20, 35, 0xFFFFFF, "-> Glynn");
	else if (e->opt1 == 4)
		mlx_string_put(e->mlx, e->win, 20, 35, 0xFFFFFF, "-> Newton");
	else if (e->opt1 == 5)
		mlx_string_put(e->mlx, e->win, 20, 35, 0xFFFFFF, "-> Tricorn");
	else if (e->opt1 == 6)
		mlx_string_put(e->mlx, e->win, 20, 35, 0xFFFFFF, "-> Broco");
}
