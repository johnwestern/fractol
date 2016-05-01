/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:37:49 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/01 02:51:38 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook(int button, int x, int y, t_data *e)
{
	if (e->start == 1)
	{
		if (x < WDH && x > 0 && y < HGHT && y > 0 && button == 1)
		{
			e->mouse_x -= 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / e->zoom;
			e->mouse_y -= (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom;
			e->zoom *= 1.05;
		}
		if (x < WDH && x > 0 && y < HGHT && y > 0 && button == 2)
		{
			e->mouse_x -= 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / e->zoom;
			e->mouse_y -= (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom;
			e->zoom /= 1.05;
		}
		draw_mandelbrot(e);
	}
	return (0);
}

static void		auto_iter(t_data *e)
{
	e->ato = 1;
	if (e->zoom > 1 && e->zoom <= 100)
		e->maxiter = 60 + 50 * (e->zoom / 100);
	if (e->zoom > 100 && e->zoom <= 1000)
		e->maxiter = 110 + 50 * (e->zoom / 1000);
	if (e->zoom > 1000 && e->zoom <= 5000)
		e->maxiter = 160 + 50 * (e->zoom / 5000);
	if (e->zoom > 5000 && e->zoom <= 10000)
		e->maxiter = 210 + 40 * (e->zoom / 10000);
	if (e->zoom > 10000 && e->zoom <= 20000)
		e->maxiter = 250 + 55 * (e->zoom / 20000);
	if (e->zoom > 20000 && e->zoom <= 60000)
		e->maxiter = 305 + 50 * (e->zoom / 60000);
	if (e->zoom > 60000 && e->zoom <= 100000)
		e->maxiter = 355 + 50 * (e->zoom / 100000);
	if (e->zoom > 100000)
		e->maxiter = 395;
}

static void		reset_val(t_data *e)
{
	e->start = 1;
	e->zoom = 1;
	e->offset_y = 0;
	e->offset_x = -0.5;
	e->mouse_y = 0;
	e->mouse_x = 0;
	e->ato = 0;
	e->hud = 1;
	e->maxiter = 60;
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
	{
		if (e->hud == 1)
			e->hud = 0;
		else
			e->hud = 1;
	}
	if (key == 0)
		e->zoom /= 1.05;
	if ((key == 24 && e->maxiter <= 390) || (key == 27))
	{
		if (key == 24)
			e->maxiter += 5;
		if (key == 27 && e->maxiter > 35)
			e->maxiter -= 5;
		else if (key == 27 && e->maxiter > 30)
			e->maxiter -= 1;
		e->ato = 0;
	}
	if (key == 126 || key == 125 || key == 123 || key == 124)
		arr_move(key, e);
	if (e->start == 1)
		draw_mandelbrot(e);
	return (0);
}
