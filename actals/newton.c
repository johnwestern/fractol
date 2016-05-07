/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 20:53:00 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/08 00:40:29 by jdavin           ###   ########.fr       */
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
	register t_cplx	poule;
	double 			nwt;
	int				i;
	double			x;


	i = 0;
	tmp.x = 1.5 * (px - WDH / 2) / (0.5 * e->zoom * WDH) + e->offset_x + \
	e->mouse_x;
	tmp.y = (py - HGHT / 2) / (0.5 * e->zoom * HGHT) + e->offset_y + e->mouse_y;
	while (i < e->mitr && (tmp.x * tmp.x + tmp.y * tmp.y) < 4)
	{
		poule.x = tmp.x * tmp.x;
		poule.y = tmp.y * tmp.y;
		nwt = 3.0 * ((poule.x - poule.y) * (poule.x - poule.y) +\
		 4.0 * poule.x * poule.y);
		if (nwt == 0)
			nwt = 0.000001;
		x = tmp.x;
		tmp.x = (2/3) * tmp.x + (poule.x - poule.y) / nwt + c.x;
		tmp.y = (2/3) * tmp.y - (2 * x * tmp.y) / nwt + c.y;
		i++;
	}
	return (i);
}

void				draw_newton(t_data *e)
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
			c.x = 0.415483 - fabs(e->motion_x / 2);
			c.y = 0.361111 - fabs(e->motion_y);
			i = iter(e, c, x, y);
			set_pixel(x, y, e, i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_str(e);
}