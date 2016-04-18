/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:25:39 by jdavin            #+#    #+#             */
/*   Updated: 2016/01/04 11:23:12 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nw;

	if (content_size >= 65535)
		return (NULL);
	if (!(nw = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		nw->content = NULL;
		nw->content_size = 0;
		nw->next = NULL;
	}
	else
	{
		if (content_size > 0)
		{
			nw->content = (void *)malloc(content_size);
			nw->content = ft_memcpy(nw->content, content, content_size);
		}
		else
			nw->content = NULL;
		nw->content_size = content_size;
		nw->next = NULL;
	}
	return (nw);
}
