/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:11:45 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/27 23:19:44 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			expose_hook(t_data *e)
{
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	draw_mandelbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}
