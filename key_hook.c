/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:37:49 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/27 23:37:17 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode, t_data *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 12)
		e->zoom += 40;
	if (keycode == 0)
		e->zoom -= 40;
	if (keycode == 24)
		e->maxiter += 20;
	if (keycode == 27)
		e->maxiter -= 20;
	if (keycode == 126)
		e->offset_y += 40;
	if (keycode == 125)
		e->offset_y -= 40;
	if (keycode == 123)
		e->offset_x += 40;
	if (keycode == 124)
		e->offset_x -= 40;
	expose_hook(e);
	return (0);
}
