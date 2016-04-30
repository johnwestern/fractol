/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:38:27 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/30 02:54:57 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_pixel(int x, int y, t_data *e)
{
	int		octet;
	int		pos;

	octet = e->sizeline / WDH;
	pos = x * octet + y * e->sizeline;
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

void				draw_mandelbrot(t_data *e)
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
			i = iter(e->maxiter, c);
			set_i_color(i % 400, e);
			set_pixel(x, y, e);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_string_put(e->mlx, e->win, 20, 10, 0xFFFFFF, "Zoom x");
	mlx_string_put(e->mlx, e->win, 90, 10, 0xFFFFFF, ft_itoa(e->zoom));
	mlx_string_put(e->mlx, e->win, 20, 30, 0xFFFFFF, "Iter =");
	mlx_string_put(e->mlx, e->win, 90, 30, 0xFFFFFF, ft_itoa(e->maxiter));
	mlx_string_put(e->mlx, e->win, 910, 10, 0xFFFFFF, "Press [R] to restore default values");
}
