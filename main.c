/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:07:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/27 22:58:41 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				ft_init(t_data *e)
{
	e->offset_x = WDH / 2;
	e->offset_y = HGHT / 2;
	e->zoom = 340;
	e->maxiter = 150;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WDH, HGHT, "Fract\'ol");
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_loop(e->mlx);
}

int				main(int ac, char **av)
{
	t_data		e;

	if (ac == 1)
		ft_init(&e);
	else
		put_usage_error(av[0]);
	return (0);
}
