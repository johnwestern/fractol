/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 21:39:52 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/07 01:35:24 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void		setrgb(t_color *color, char b, char g, char r)
{
	color->rgb[0] = r;
	color->rgb[1] = g;
	color->rgb[2] = b;
	color->rgb[3] = 0;
}

static void		enhanced_start(int i, t_data *e, t_flcl *f)
{
	f->l = 0.5 * (i < e->mitr);
	f->a = 1 - fabs(2 * f->l - 1);
	f->b = f->a * (1.0 - fabs(fmod((i / 50.0), 2) - 1.0));
	if (i >= 0 && i < 50)
		setrgb(&e->color, 0, 0, f->b * 255);
	else if (i >= 50 && i < 100)
		setrgb(&e->color, f->a * 255, f->a * 255 / 1.5, f->b * 255 / 50);

}

static void		enhanced_end(int i, t_data *e, t_flcl *f)
{
	f->l = 0.5 * (i < (e->mitr - 250));
	f->a = 1 - fabs(2 * f->l - 1);
	f->b = f->a * (1.0 - fabs(fmod((i / 50.0), 2) - 1.0));
	if (i >= 50 && i < 100)
		setrgb(&e->color, f->b * 255, f->a * 255, 0);
	else if (i >= 100 && i < 150)
		setrgb(&e->color, f->b * 255, f->a * 255, 0);
	else if (i >= 150 && i < 200)
		setrgb(&e->color, f->a * 255, f->b * 255, 0);
	else if (i >= 200 && i < 250)
		setrgb(&e->color, f->a * 255, 0, f->b * 255);
	else if (i >= 250 && i < 300)
		setrgb(&e->color, f->a * 255, 0, f->b * 255);
	else if (i >= 250 && i < 350)
		setrgb(&e->color, f->a * 255, f->a * 255 / 2, f->a * 255 / 4);
}

void			eclips_color(int i, t_data *e)
{
	auto t_flcl		f;

	if (i >= 0 && i < 100)
		enhanced_start(i, e, &f);
	else if (i >= 300 && i < 600)
		enhanced_end(i - 250, e, &f);
	f.l = 0.5 * (i < e->mitr);
	f.a = 1 - fabs(2 * f.l - 1);
	f.b = f.a * (1.0 - fabs(fmod((i / 100.0), 2) - 1.0));
	if (i >= 100 && i < 200)
		setrgb(&e->color, f.a * 255, f.b * 255 / 2, 0);
	else if (i >= 200 && i < 300)
		setrgb(&e->color, f.a * 255, f.b * 255, 0);
}
