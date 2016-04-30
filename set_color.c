/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 21:39:52 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/30 03:04:45 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		setrgb(t_color *color, char r, char g, char b)
{
	color->rgb[0] = b;
	color->rgb[1] = g;
	color->rgb[2] = r;
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
	b = a * (1 - fabs(fmod((i / 21.0), 2) - 1));
	c = l - 0.5 * a;
	if (i >= 0 && i < 21)
		setrgb(&e->color, (a + c) * 255, (b + c) * 255, (0 + c) * 255);
	else if (i >= 21 && i < 42)
		setrgb(&e->color, (b + c) * 255, (a + c) * 255, (0 + c) * 255);
	else if (i >= 42 && i < 102)
		setrgb(&e->color, (0 + c) * 255, (a + c) * 255, (b + c) * 255);
	else if (i >= 102 && i < 204)
		setrgb(&e->color, (0 + c) * 255, (b + c) * 255, (a + c) * 255);
	else if (i >= 200 && i < 400)
		setrgb(&e->color, (b + c) * 255, (0 + c) * 255, (a + c) * 255);
	else
		setrgb(&e->color, 255, 255, 255);
}

