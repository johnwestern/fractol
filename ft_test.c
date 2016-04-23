/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:20:32 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/23 17:07:56 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_test(t_data *e)
{
	t_color			color;
	int				octet;
	int				pos;

	color.rgb[0] = 255;
	color.rgb[1] = 0;
	color.rgb[2] = 0;
	color.rgb[3] = 0;
	octet = e->sizeline / WDH;
	pos = 240 * e->sizeline;
	while (pos < 481 * e->sizeline)
	{
		if (pos % e->sizeline == 0)
		{
			color.rgb[2]++;
			color.rgb[1]++;
		}
		if (ft_memcmp(e->data + pos, &(color.color), octet) != 0)
			ft_memcpy(e->data + pos, &(color.color), octet);
		pos += octet;
	}
}
