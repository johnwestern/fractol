/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 14:20:32 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/23 20:30:45 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_test(t_data *e)
{
	t_color			color;
	int				octet;
	int				pos;


	octet = e->sizeline / WDH;
	pos = 0;

	color.rgb[0] = 225;
	color.rgb[1] = 225;
	color.rgb[2] = 225;
	color.rgb[3] = 0;
	while (pos < 45 * e->sizeline)
	{
		if (pos % e->sizeline == 0)
		{
			color.rgb[0] -= 5;
			color.rgb[1] -= 5;
			color.rgb[2] -= 5;
		}
		if (ft_memcmp(e->data + pos, &(color.color), octet) != 0)
			ft_memcpy(e->data + pos, &(color.color), octet);
		pos += octet;
	}
	color.rgb[2] = 45;
	while (pos < 180 * e->sizeline)
	{
		if (pos % e->sizeline == 0)
		{
			color.rgb[2] += 1;
		}
		if (ft_memcmp(e->data + pos, &(color.color), octet) != 0)
			ft_memcpy(e->data + pos, &(color.color), octet);
		pos += octet;
	}
	while (pos < 360 * e->sizeline)
	{
		if (pos % e->sizeline == 0)
		{
			color.rgb[2]--;
			color.rgb[1]++;	
		}
		if (ft_memcmp(e->data + pos, &(color.color), octet) != 0)
			ft_memcpy(e->data + pos, &(color.color), octet);
		pos += octet;
	}
	while (pos < 540 * e->sizeline)
	{
		if (pos % e->sizeline == 0)
		{
			color.rgb[1]--;
			color.rgb[0]++;
		}
		if (ft_memcmp(e->data + pos, &(color.color), octet) != 0)
			ft_memcpy(e->data + pos, &(color.color), octet);
		pos += octet;
	}
	while (pos < 675 * e->sizeline)
	{
		if (pos % e->sizeline == 0)
		{
			color.rgb[0] -= 1;
		}
		if (ft_memcmp(e->data + pos, &(color.color), octet) != 0)
			ft_memcpy(e->data + pos, &(color.color), octet);
		pos += octet;
	}
	color.rgb[0] = 0;
	while (pos < 720 * e->sizeline)
	{
		if (pos % e->sizeline == 0)
		{
			color.rgb[0] += 5;
			color.rgb[1] += 5;
			color.rgb[2] += 5;
		}
		if (ft_memcmp(e->data + pos, &(color.color), octet) != 0)
			ft_memcpy(e->data + pos, &(color.color), octet);
		pos += octet;
	}
}
