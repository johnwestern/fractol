/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:35:37 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/05 00:12:56 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			motion_hook(int x, int y, t_data *e)
{
	if (x < WDH && x > 0 && y < HGHT && y > 0 && e->start == 0 && e->opt1 == 2)
	{
		e->motion_x = 1.5 * (WDH * 0.5 - x) / (WDH / 2) * 1 / \
		e->zoom + e->offset_x;
		e->motion_y = (HGHT * 0.5 - y) / (HGHT / 2) * 1 / e->zoom + e->offset_y;
	}
	draw_option(e);
	return (0);
}
