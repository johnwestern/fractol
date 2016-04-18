/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:51:28 by jdavin            #+#    #+#             */
/*   Updated: 2016/01/04 11:24:43 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_intlen(unsigned int n)
{
	int				count;

	count = 1;
	while (9 < n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char			*itoa_neg(unsigned int n)
{
	char			*s;
	int				i;

	i = ft_intlen(n) + 1;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	s[0] = '-';
	s[i] = '\0';
	i--;
	while (i > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

static char			*itoa_pos(unsigned int n)
{
	char			*s;
	int				i;

	i = ft_intlen(n);
	s = (char *)malloc(sizeof(char) * i);
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	i--;
	while (i >= 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

char				*ft_itoa(int n)
{
	unsigned int	nb;
	char			*s;

	if (n == 0)
	{
		s = (char *)malloc(sizeof(char) * 2);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (n > 0)
		return (itoa_pos(n));
	if (n < 0)
	{
		nb = -n;
		return (itoa_neg(nb));
	}
	return (NULL);
}
