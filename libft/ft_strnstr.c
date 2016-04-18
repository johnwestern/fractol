/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 19:55:51 by jdavin            #+#    #+#             */
/*   Updated: 2015/11/29 15:35:46 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && i < len)
	{
		if ((len - i) > (ft_strlen(s2) - 1))
		{
			if (s1[i] == s2[0] && ft_strncmp(s1 + i, s2, len) == 0)
				return ((char *)s1 + i);
			if (s1[i] == s2[0] && ft_strncmp(s1 + i, s2, ft_strlen(s2)) == 0)
				return ((char *)s1 + i);
		}
		i++;
	}
	if (s2[0] == '\0')
		return ((char *)s1);
	else
		return (0);
}
