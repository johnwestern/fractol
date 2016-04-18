/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 20:25:22 by jdavin            #+#    #+#             */
/*   Updated: 2016/04/05 15:19:33 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				stocktoline(char **line, char **stock)
{
	char				*tmp;
	int					len;

	if (!(*stock))
		return (0);
	if ((tmp = ft_strchr(*stock, '\n')))
	{
		len = tmp - *stock;
		*line = ft_strsub(*stock, 0, len);
		if (ft_strlen(++tmp))
			*stock = ft_strdup(tmp);
		else
			*stock = NULL;
	}
	else if (ft_strlen(*stock))
	{
		*line = *stock;
		*stock = NULL;
	}
	if (tmp != NULL)
		return (1);
	return (0);
}

static int				cpy_buf(char *buf, char **line, char **stock)
{
	char				*rest;
	char				*tmp;

	if ((rest = ft_strchr(buf, '\n')))
	{
		rest[0] = '\0';
		tmp = ft_strjoin(*line, buf);
		free(*line);
		*line = tmp;
		if (ft_strlen(++rest))
			*stock = ft_strdup(rest);
	}
	else
	{
		tmp = ft_strjoin(*line, buf);
		free(*line);
		*line = tmp;
	}
	if (rest != NULL)
		return (1);
	return (0);
}

int						get_next_line(int const fd, char **line)
{
	static char			*stock[256] = {NULL};
	char				*buf;
	int					ret;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > 256)
		return (-1);
	*line = NULL;
	buf = ft_strnew(BUFF_SIZE);
	if (stocktoline(line, &stock[fd]) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (cpy_buf(buf, line, &stock[fd]) == 1)
			break ;
	}
	free(buf);
	if (ret > 0 || *line)
		return (1);
	return (ret);
}
