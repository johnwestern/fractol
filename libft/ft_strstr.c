/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:49:59 by jdavin            #+#    #+#             */
/*   Updated: 2015/11/30 13:21:05 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0] && ft_strncmp(s1 + i, s2, ft_strlen(s2)) == 0)
			return ((char *)s1 + i);
		i++;
	}
	if (s2[0] == '\0')
		return ((char *)s1);
	else
		return (0);
}
