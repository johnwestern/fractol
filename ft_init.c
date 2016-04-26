/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:23:26 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/26 02:27:23 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot_scale(t_data *e)
{
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->maxiter = 50;
	e->image_x = (e->x2 - e->x1) * e->zoom;
	e->image_y = (e->y2 - e->y1) * e->zoom;
}

void				mandelbrot_calc(t_data *e, int x, int y)
{
	e->c_r = (x - e->offset_x) * (1 / e->zoom);
	e->c_i = (y - e->offset_y) * (1 / e->zoom);
	e->z_r = 0;
	e->z_i = 0;
}

void				init_calc(t_data *e)
{
	e->c_r = 0;
	e->c_i = 0;
	e->z_r = 0;
	e->z_i = 0;
}

void				ft_init(void)
{
	t_data			e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WDH, HGHT, "Fract\'ol");
	e.img = mlx_new_image(e.mlx, WDH, HGHT);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sizeline, &e.endian);
	e.offset_x = WDH / 2;
	e.offset_y = HGHT / 2;
	e.zoom = 100;
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
 