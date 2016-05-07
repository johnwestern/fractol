/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:37:49 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/07 01:49:09 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int				mouse_hook(int b, int x, int y, t_data *e)
{
	if (e->st == 1)
	{
		if (x < WDH && x > 0 && y < HGHT && y > 0 && (b == 1 || b == 2))
		{
			e->mouse_x += 1.5 * (x - WDH * 0.5) / (WDH * 0.5)  / e->zoom;
			e->mouse_y += (y - HGHT * 0.5) / (HGHT * 0.5)  / e->zoom;
			if (b == 1)
				e->zoom *= 1.15;
			else
				e->zoom /= 1.15;
		}
		else if (x < WDH && x > 0 && y < HGHT && y > 0 && (b == 4 || b == 5))
		{
			e->mouse_x += 1.5 * (x - WDH * 0.5) / (WDH * 0.5)  / e->zoom;
			e->mouse_y += (y - HGHT * 0.5) / (HGHT * 0.5)  / e->zoom;
			if (b == 4)
				e->zoom *= 1.15;
			else
				e->zoom /= 1.15;
			e->offset_x += 1.5 * (WDH * 0.5 - x) / (WDH * 0.5) / e->zoom;
			e->offset_y += (HGHT * 0.5 - y) / (HGHT * 0.5) / e->zoom;
		}
		draw_option(e);
	}
	return (0);
}

static void		auto_iter(t_data *e)
{
	e->ato = 1;
	if (e->zoom > 1 && e->zoom <= 2000)
		e->mitr = 150 + 50 * (e->zoom / 2000);
	else if (e->zoom > 2000 && e->zoom <= 10000)
		e->mitr = 200 + 50 * (e->zoom / 10000);
	else if (e->zoom > 10000 && e->zoom <= 300000)
		e->mitr = 250 + 100 * (e->zoom / 300000);
	else if (e->zoom > 300000 && e->zoom <= 10000000)
		e->mitr = 350 + 100 * (e->zoom / 10000000);
	else if (e->zoom > 10000000 && e->zoom <= 100000000)
		e->mitr = 450 + 149 * (e->zoom / 150000000);
	else if (e->zoom > 150000000)
		e->mitr = 599;
}

static void		reset_val(t_data *e)
{
	e->mouse_y = 0;
	e->mouse_x = 0;
	e->ato = 0;
	e->hud = 0;
	e->mitr = 100;
	e->st = 1;
	e->zoom = 1;
	reset_offset(e);
}

static void		arr_move(int key, t_data *e)
{
	if (e->st == 1)
	{
		if (key == 126)
			e->offset_y -= 0.05 * 1 / e->zoom;
		else if (key == 125)
			e->offset_y += 0.05 * 1 / e->zoom;
		else if (key == 123)
			e->offset_x -= 0.075 * 1 / e->zoom;
		else if (key == 124)
			e->offset_x += 0.075 * 1 / e->zoom;
	}
	if (e->st == 0)
		fractal_switch(key, e);
}

int				key_hook(int k, t_data *e)
{
	if (k == 53)
		exit(0);
	else if (k == 11)
	{
		e->st = 0;
		e->hud = 1;
		option1(e);
	}
	else if (k == 49)
		reset_val(e);
	else if ((k == 8 && e->st == 1) || ((k == 125 || k == 126) && e->st == 0))
		change_color_set(e, k);
	else if (k == 12 && (e->zoom *= 1.15))
		auto_iter(e);
	else if (k == 0)
		e->zoom /= 1.15;
	else if (k == 4)
		hud_switch(e);
	else if (k == 24 || (k == 27))
		man_iter(k, e);
	else if (k == 126 || k == 125 || k == 123 || k == 124)
		arr_move(k, e);
	if (e->st == 1 || e->opt1 == 2)
		draw_option(e);
	return (0);
}
