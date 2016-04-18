/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:23:26 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/18 17:30:55 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_init(void)
{
	t_data			e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WDH, HGHT, "Fract\'ol");
	e.img = mlx_new_image(e.mlx, WDH, HGHT);
	mlx_loop(e.mlx);
}
