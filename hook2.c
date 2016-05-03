/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 22:10:56 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/03 17:35:17 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_color_set(t_data *e)
{
	if (e->cop == 0)
	{
		e->cop = 1;
		draw_option(e);
	}
	else
	{
		e->cop = 0;
		draw_option(e);
	}
}

void		draw_option(t_data *e)
{
	if (e->opt1 == 0)
		draw_mandelbrot(e);
	if (e->opt1 == 1)
		draw_burning_ship(e);
	if (e->opt1 == 2)
		draw_julia(e);
}

void		hud_switch(t_data *e)
{
	if (e->hud == 1)
		e->hud = 0;
	else
		e->hud = 1;
}

void		man_iter(int key, t_data *e)
{
	if (key == 24 && e->mitr <= 594)
		e->mitr += 5;
	if (key == 27 && e->mitr >= 35)
		e->mitr -= 5;
	e->ato = 0;
}

void		reset_offset(t_data *e)
{
	if (e->opt1 == 0)
	{
		e->offset_y = 0;
		e->offset_x = -0.5;
	}
	if (e->opt1 == 1)
	{
		e->offset_y = 0;
		e->offset_x = -1;
	}
	if (e->opt1 == 2)
	{
		e->offset_y = 0;
		e->offset_x = -1;
	}
}
