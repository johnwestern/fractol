/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_i_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 21:39:52 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/27 22:28:22 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_setColorRGB(t_color *color, char r, char g, char b)
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
	b = a * (1 - fabs(fmod((i / 50.0), 2) - 1));
	c = l - 0.5 * a;
	if (i >= 0 && i < 50)
		ft_setColorRGB(&e->color, (a + c) * 255, (b + c) * 255, (0 + c) * 255);
	else if (i >= 50 && i < 100)
		ft_setColorRGB(&e->color, (b + c) * 255, (a + c) * 255, (0 + c) * 255);
	else if (i >= 100 && i < 150)
		ft_setColorRGB(&e->color, (0 + c) * 255, (a + c) * 255, (b + c) * 255);
	else if (i >= 150 && i < 200)
		ft_setColorRGB(&e->color, (0 + c) * 255, (b + c) * 255, (a + c) * 255);
	else if (i >= 200 && i < 250)
		ft_setColorRGB(&e->color, (b + c) * 255, (0 + c) * 255, (a + c) * 255);
	else
		ft_setColorRGB(&e->color, 255, 255, 255);
}
