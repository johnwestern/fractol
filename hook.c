/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:37:49 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/30 00:29:52 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_hook(int button, int x, int y, t_data *e)
{
	if (x < WDH && x > 0 && y < HGHT && y > 0 && button == 1)
	{
		e->mouse_x -= 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / e->zoom;
		e->mouse_y -= (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom;
		e->zoom *= 1.15;
	}
	if (x < WDH && x > 0 && y < HGHT && y > 0 && button == 2)
	{
		e->mouse_x -= 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / e->zoom;
		e->mouse_y -= (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom;
		e->zoom /= 1.15;
	}
	draw_mandelbrot(e);
	return (0);
}

static void		reset_val(t_data *e)
{
	e->zoom = 1;
	e->offset_y = 0;
	e->offset_x = -0.5;
	e->mouse_y = 0;
	e->mouse_x = 0;
	e->maxiter = 64;
}

int				key_hook(int keycode, t_data *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
		reset_val(e);
	if (keycode == 12)
		e->zoom *= 1.05;
	if (keycode == 0)
		e->zoom /= 1.05;
	if (keycode == 24)
		e->maxiter += 8;
	if (keycode == 27)
		e->maxiter -= 8;
	if (keycode == 126)
		e->offset_y -= 0.05 * 1 / e->zoom;
	if (keycode == 125)
		e->offset_y += 0.05 * 1 / e->zoom;
	if (keycode == 123)
		e->offset_x -= 0.075 * 1 / e->zoom;
	if (keycode == 124)
		e->offset_x += 0.075 * 1 / e->zoom;
	draw_mandelbrot(e);
	return (0);
}
