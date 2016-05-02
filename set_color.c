/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 21:39:52 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/02 17:40:02 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		setrgb(t_color *color, char b, char g, char r)
{
	color->rgb[0] = r;
	color->rgb[1] = g;
	color->rgb[2] = b;
	color->rgb[3] = 0;
}

static void		enenced_start_color(int i, t_data *e, t_flcl *f)
{
	f->a =  0.11 + i / 50;
	setrgb(&e->color, 0, 0, f->a * 255);
}

void			set_i_color(int i, t_data *e)
{
	t_flcl		f;
	
	f.l = 0.5 * (i < e->mitr);
	f.a = 1 - fabs(2 * f.l - 1);
	f.b = f.a * (1.0 - fabs(fmod((i / 100.0), 2) - 1.0));
	f.c = f.l - 0.5 * f.a;
	if (i >= 0 && i < 50)
		enenced_start_color(i, e, &f);
	else if (i >= 50 && i < 100)
		setrgb(&e->color, (f.a + f.c) * 255, (f.b + f.c) * 255, f.c * 255);
	else if (i >= 100 && i < 200)
		setrgb(&e->color, (f.b + f.c) * 255, (f.a + f.c) * 255, f.c * 255);
	else if (i >= 200 && i < 300)
		setrgb(&e->color, f.c * 255, (f.a + f.c) * 255, (f.b + f.c) * 255);
	else if (i >= 300 && i < 400)
		setrgb(&e->color, f.c * 255, (f.b + f.c) * 255, (f.a + f.c) * 255);
	else if (i >= 400 && i < 500)
		setrgb(&e->color, 0, f.c * 255, (f.a + f.c) * 255);
	else if (i >= 500 && i < 600)
		setrgb(&e->color, 0, 0, (f.a - f.c) * 255);
	else if (i >= 360 && i < 500)
		setrgb(&e->color, 0, 0, 13 + 0.95 * (f.a + f.c) * 255);
}

