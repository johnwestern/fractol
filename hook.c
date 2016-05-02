/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:37:49 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/02 14:58:06 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook(int but, int x, int y, t_data *e)
{
	if (e->start == 1)
	{
		if (x < WDH && x > 0 && y < HGHT && y > 0 && (but == 1 || but == 4))
		{
			e->mouse_x -= 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / e->zoom;
			e->mouse_y -= (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom;
			e->zoom *= 1.05;
		}
		if (x < WDH && x > 0 && y < HGHT && y > 0 && (but == 2 || but == 5))
		{
			e->mouse_x -= 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / e->zoom;
			e->mouse_y -= (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom;
			e->zoom /= 1.05;
		}
		draw_option(e);
	}
	return (0);
}

static void		auto_iter(t_data *e)
{
	e->ato = 1;
	if (e->zoom > 1 && e->zoom <= 100)
		e->mitr = 60 + 60 * (e->zoom / 100);
	if (e->zoom > 100 && e->zoom <= 1000)
		e->mitr = 120 + 60 * (e->zoom / 1000);
	if (e->zoom > 1000 && e->zoom <= 5000)
		e->mitr = 180 + 60 * (e->zoom / 5000);
	if (e->zoom > 5000 && e->zoom <= 10000)
		e->mitr = 240 + 60 * (e->zoom / 10000);
	if (e->zoom > 10000 && e->zoom <= 30000)
		e->mitr = 300 + 60 * (e->zoom / 30000);
	if (e->zoom > 20000 && e->zoom <= 100000)
		e->mitr = 360 + 35 * (e->zoom / 100000);
	if (e->zoom > 100000)
		e->mitr = 395;
}

static void		reset_val(t_data *e)
{
	e->mouse_y = 0;
	e->mouse_x = 0;
	e->ato = 0;
	e->hud = 0;
	e->mitr = 60;
	e->start = 1;
	e->zoom = 1;
	reset_offset(e);
}

static void		arr_move(int key, t_data *e)
{
	if (key == 126)
		e->offset_y -= 0.05 * 1 / e->zoom;
	if (key == 125)
		e->offset_y += 0.05 * 1 / e->zoom;
	if (key == 123)
		e->offset_x -= 0.075 * 1 / e->zoom;
	if (key == 124)
		e->offset_x += 0.075 * 1 / e->zoom;
}

int				key_hook(int key, t_data *e)
{
	if (key == 53)
		exit(0);
	if (key == 15)
		reset_val(e);
	if (key == 12 && (e->zoom *= 1.05))
		auto_iter(e);
	if (key == 4)
		hud_switch(e);
	if (key == 0)
		e->zoom /= 1.05;
	if (key == 24 || (key == 27))
		man_iter(key, e);
	if (key == 126 || key == 125 || key == 123 || key == 124)
		arr_move(key, e);
	if (e->start == 1)
		draw_option(e);
	return (0);
}
