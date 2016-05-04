/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:35:37 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/04 21:45:03 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			j_mouse_hook(int but, int x, int y, t_data *e)
{
	if (x < WDH && x > 0 && y < HGHT && y > 0 && (but == 1 || but == 4))
	{
		e->mouse_x = 1 * (WDH * 0.5 - x) / WDH;
		e->mouse_y = (HGHT * 0.5 - y) / HGHT;
	}
	if (x < WDH && x > 0 && y < HGHT && y > 0 && (but == 2 || but == 5))
	{
		e->mouse_x = 1 * (WDH * 0.5 - x) / WDH;
		e->mouse_y = (HGHT * 0.5 - y) / HGHT;
	}
	draw_option(e);
	return (0);
}
