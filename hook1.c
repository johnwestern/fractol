/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:35:37 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/06 17:38:12 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_hook(int x, int y, t_data *e)
{
	if (x < WDH && x > 0 && y < HGHT && y > 0 && e->start == 0)
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
		if (e->opt1 == 0)
			e->opt1 = 2;
		else if (e->opt1 == 1)
			e->opt1 = 0;
		else
			e->opt1 = 1;
	}
	if (key == 124)
	{
		if (e->opt1 == 0)
			e->opt1 = 1;
		else if (e->opt1 == 1)
			e->opt1 = 2;
		else
			e->opt1 = 0;
	}
	option1(e);
}