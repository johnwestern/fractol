/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:17:50 by jdavin            #+#    #+#             */
/*   Updated: 2015/12/28 17:41:10 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s1;

	i = 0;
	if (s != NULL && f != NULL)
	{
		s1 = ft_strdup(s);
		if (!s1)
			return (NULL);
		while (s[i])
		{
			s1[i] = (*f)(s[i]);
			i++;
		}
		return (s1);
	}
	return (NULL);
}
