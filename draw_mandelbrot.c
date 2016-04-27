/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:38:27 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/28 00:04:38 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int 			iter(int maxiter, t_cplx c)
{
	t_cplx			tmp;
	int 			i;
	float			x;

	i = 0;
	tmp.x = 0;
	tmp.y = 0;
	while (i < maxiter && (tmp.x * tmp.x + tmp.y * tmp.y) < 4)
	{
		i++;	
		x = tmp.x;
		tmp.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		tmp.y = (2 * x * tmp.y) + c.y;
	}
	return (i);
}

void				draw_mandelbrot(t_data *e)
{
	int				i;
	int				x;
	int				y;
	t_cplx			c;

	y = 0;
	while (y < HGHT)
	{
		x = 0;
		while (x < WDH)
		{
			c.x = (x - e->offset_x - 100) / e->zoom;
			c.y = (y - e->offset_y) / e->zoom;
			i = iter(e->maxiter, c);
			set_i_color(i % 250, e);
			set_pixel(x, y, e);
			x++;
		}
		y++;
	}
}
