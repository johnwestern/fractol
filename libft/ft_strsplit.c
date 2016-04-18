/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:19:45 by jdavin            #+#    #+#             */
/*   Updated: 2016/01/04 11:25:55 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenword(const char *s, char c, int i)
{
	int			a;

	a = i;
	while (s[a] != c && s[a] != '\0')
		a++;
	return (a - i);
}

static int		ft_nbword(char const *s, char c)
{
	int			i;
	int			a;

	a = 0;
	i = 0;
	if (s[0] != c)
		i = 1;
	while (s[a] != '\0')
	{
		if (s[a] == c && s[a + 1] != c && s[a + 1] != '\0' && s[a] != '\0')
		{
			a++;
			i++;
		}
		a++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int			a;
	int			b;
	int			i;
	int			lol;
	char		**str;

	lol = -1;
	a = 0;
	i = -1;
	str = (char **)malloc(sizeof(char *) * ft_nbword(s, c) + 1);
	if (!str)
		return (NULL);
	while (++lol < ft_nbword(s, c) && ++i >= 0)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i + 1] != '\0' && s[i] != '\0')
		{
			b = ft_lenword(s, c, i);
			str[a++] = ft_strsub(s, i, b);
			i = i + b - 1;
		}
	}
	str[a] = NULL;
	return (str);
}
