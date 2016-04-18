/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 02:57:06 by jdavin            #+#    #+#             */
/*   Updated: 2015/12/08 15:59:47 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putunsignednbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (n >= 0 && n < 10)
		ft_putchar_fd(n + '0', fd);
	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd);
		ft_putunsignednbr_fd(nb, fd);
	}
}
