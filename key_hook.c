/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 17:37:49 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/18 17:41:41 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode, t_data *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}
