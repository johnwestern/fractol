/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:17:05 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/07 01:36:06 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void			set_pixel(int x, int y, t_data *e, int i)
{
	int				octet;
	int				pos;

	octet = e->sizeline / WDH;
	pos = x * octet + y * e->sizeline;
	if (e->cop == 0)
		eclips_color(i, e);
	if (e->cop == 1)
		bw_color(i, e);
	if (e->cop == 2)
		red_color(i, e);
	if (ft_memcmp(e->data + pos, &e->color.color, octet) != 0)
		ft_memcpy(e->data + pos, &e->color.color, octet);
}

static int			iter(t_data *e, t_cplx c)
{
	t_cplx			tmp;
	int				i;
	float			x;

	i = 0;
	tmp.x = e->motion_y;
	tmp.y = e->motion_y;
	while (i < e->mitr && (tmp.x * tmp.x + tmp.y * tmp.y) < 4)
	{
		x = tmp.x;
		tmp.x = fabs(tmp.x * tmp.x - tmp.y * tmp.y + c.x);
		tmp.y = fabs((2 * x * tmp.y) + c.y);
		i++;
	}
	return (i);
}

void				draw_burning_ship(t_data *e)
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
			i = iter(e, c);
			set_pixel(x, y, e, i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_str(e);
}
