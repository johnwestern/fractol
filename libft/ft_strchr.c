/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:24:50 by jdavin            #+#    #+#             */
/*   Updated: 2016/03/16 14:37:06 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char*)s;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s1 + i);
		i++;
	}
	if (s[i] == c)
		return (s1 + i);
	return (NULL);
}
