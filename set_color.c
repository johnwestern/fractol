/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 21:39:52 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/30 13:17:05 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		setrgb(t_color *color, char r, char g, char b)
{
	color->rgb[0] = r;
	color->rgb[1] = g;
	color->rgb[2] = b;
	color->rgb[3] = 0;
}

void			set_i_color(int i, t_data *e)
{
	float		a;
	float		b;
	float		c;
	float		l;

	l = 0.5 * (i < e->maxiter);
	a = 1 - fabs(2 * l - 1);
	b = a * (1.0 - fabs(fmod((i / 60.0), 2) - 1.0));
	c = l - 0.5 * a;
	if (i >= 0 && i < 60)
		setrgb(&e->color, (a + c) * 255, (b + c) * 255, (0 + c) * 255);
	else if (i >= 60 && i < 120)
		setrgb(&e->color, (b + c) * 255, (a + c) * 255, (0 + c) * 255);
	else if (i >= 120 && i < 180)
		setrgb(&e->color, (0 + c) * 255, (a + c) * 255, (b + c) * 255);
	else if (i >= 180 && i < 240)
		setrgb(&e->color, (0 + c) * 255, (b + c) * 255, (a + c) * 255);
	else if (i >= 240 && i < 300)
		setrgb(&e->color, (b + c) * 255, (0 + c) * 255, (a + c) * 255);
	else if (i >= 300 && i < 400)
		setrgb(&e->color, (a + c) * 255, (0 + c) * 255, (b + c) * 255);
	else
		setrgb(&e->color, 255, 255, 255);
}

