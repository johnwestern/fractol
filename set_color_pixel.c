/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:59:47 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/26 02:57:00 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set_color_pixel(int x, int y, t_data *e)
{
	int		octet;
	int		pos;

	octet = e->sizeline / WDH;
	pos = x * octet + y * e->sizeline;
	if (ft_memcmp(e->data + pos, &e->color.color, octet) != 0)
		ft_memcpy(e->data + pos, &e->color.color, octet);
}
