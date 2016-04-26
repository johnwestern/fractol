/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:38:27 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/26 02:58:19 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int 			iter(t_data *e)
{
	int				tmp;
	int 			i;

	i = 0;

	while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && i < e->maxiter)
	{
				
		tmp = e->z_r;
		e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
		e->z_i = 2 * e->z_i * tmp + e->c_i;
		i++;
	}
	return (i);
}

void				draw_mandelbrot(t_data *e)
{
	int				x;
	int				y;
	int				i;

	e->color.rgb[0] = 0;
	e->color.rgb[1] = 0;
	e->color.rgb[2] = 0;
	e->color.rgb[3] = 0;
	y = 0;
	i = 0;
	init_calc(e);
	mandelbrot_scale(e);
	while (y < 720)
	{
		x = 0;
		while (x < 720)
		{
			mandelbrot_calc(e, x, y);
			i = iter(e);
			if (i <= 8 && i > 1)
				e->color.rgb[0] = i * 20;
			else
				e->color.rgb[0] = 0;
			set_color_pixel(x, y, e);
			x++;
		}
		y++;
	}
}
