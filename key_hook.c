/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:37:49 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/27 23:04:46 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int				key_hook(int keycode, t_data *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 24)
		e->zoom += 40;
	if (keycode == 27)
		e->zoom -= 40;
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
