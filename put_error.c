/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 04:30:29 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/18 17:29:44 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_malloc_error(void)
{
	ft_putendl("The allocation of memory Failed. Exiting.");
	exit(0);
}

void			put_usage_error(char *av)
{
	ft_putstr("Usage : ");
	ft_putstr(av);
	ft_putendl("");
	exit(0);
}
