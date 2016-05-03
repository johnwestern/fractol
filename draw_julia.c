/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 15:09:54 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/03 17:33:31 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			set_pixel(int x, int y, t_data *e, int i)
{
	int				octet;
	int				pos;

	octet = e->sizeline / WDH;
	pos = x * octet + y * e->sizeline;
	if (e->cop == 0)
		set_eclips_color(i, e);
	if (e->cop == 1)
		set_bw_color(i, e);
	if (ft_memcmp(e->data + pos, &e->color.color, octet) != 0)
		ft_memcpy(e->data + pos, &e->color.color, octet);
}

static int			iter(int maxiter, t_cplx c)
{
	t_cplx			tmp;
	int				i;
	float			x;

	i = 0;
	tmp.x = 0;
	tmp.y = 0;
	while (i < maxiter && (tmp.x * tmp.x + tmp.y * tmp.y) < 4)
	{
		x = tmp.x;
		tmp.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
		tmp.y = (2 * x * tmp.y) + c.y;
		i++;
	}
	return (i);
}

void				draw_julia(t_data *e)
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
			c.x = 1.5 * (x - WDH / 2) / (0.5 * e->zoom * WDH) + e->offset_x + \
			e->mouse_x;
			c.y = (y - HGHT / 2) / (0.5 * e->zoom * HGHT) + e->offset_y + \
			e->mouse_y;
			i = iter(e->mitr, c);
			set_pixel(x, y, e, i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_str(e);
}
