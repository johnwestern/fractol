/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 21:39:52 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/01 12:00:15 by jdavin           ###   ########.fr       */
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
	f->a =  0.12 + i / 60;
	setrgb(&e->color, f->a * 255, 0, 0);
}

void			set_i_color(int i, t_data *e)
{
	t_flcl		f;
	
	f.l = 0.5 * (i < e->mitr);
	f.a = 1 - fabs(2 * f.l - 1);
	f.b = f.a * (1.0 - fabs(fmod((i / 60.0), 2) - 1.0));
	f.c = f.l - 0.5 * f.a;
	if (i >= 0 && i < 30)
		enenced_start_color(i, e, &f);
	else if (i >= 30 && i < 60)
		setrgb(&e->color, (f.a + f.c) * 255, (f.b + f.c) * 255, f.c * 255);
	else if (i >= 60 && i < 120)
		setrgb(&e->color, (f.b + f.c) * 255, (f.a + f.c) * 255, f.c * 255);
	else if (i >= 120 && i < 180)
		setrgb(&e->color, f.c * 255, (f.a + f.c) * 255, (f.b + f.c) * 255);
	else if (i >= 180 && i < 240)
		setrgb(&e->color, f.c * 255, (f.b + f.c) * 255, (f.a + f.c) * 255);
	else if (i >= 240 && i < 325)
		setrgb(&e->color, (f.b + f.c) * 255, f.c * 255, (f.a + f.c) * 255);
	else if (i >= 325 && i < 400)
		setrgb(&e->color, (f.a + f.c) * 255, 0, (f.b + f.c) * 255);
}

