/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glynn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 16:36:20 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/07 18:39:24 by jdavin           ###   ########.fr       */
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

static int			iter(t_data *e, t_cplx c, int px, int py)
{
	register t_cplx	tmp;
	int				i;
	double			x;

	i = 0;
	tmp.x = 1.5 * (px - WDH / 2) / (0.5 * e->zoom * WDH) + e->offset_x + \
	e->mouse_x;
	tmp.y = (py - HGHT / 2) / (0.5 * e->zoom * HGHT) + e->offset_y + e->mouse_y;
	while (i < e->mitr && (tmp.x * tmp.x + tmp.y * tmp.y) < 4)
	{
		x = tmp.x;
		tmp.x =  sqrt((tmp.x * tmp.x - tmp.y * tmp.y) *\
			(tmp.x * tmp.x - tmp.y * tmp.y)) + c.x;
		tmp.y =  sqrt((2 * x * tmp.y) * (2 * x * tmp.y)) + c.y;
		i++;
	}
	return (i);
}

void				draw_glynn(t_data *e)
{
	int				i;
	int				x;
	int				y;
	register t_cplx	c;

	y = 0;
	while (y < HGHT)
	{
		x = 0;
		while (x < WDH)
		{
			c.x = -0.739453 + e->motion_x;
			c.y = 0.081755 + e->motion_y;
			i = iter(e, c, x, y);
			set_pixel(x, y, e, i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_str(e);
}
