/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:23:43 by jayu              #+#    #+#             */
/*   Updated: 2022/01/06 15:24:24 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_read_buf(t_buf *buf, char **line)
{
	int	i;
	int	j;
	int	find;

	i = ft_strlen(*line);
	if (!ft_resize(i, buf, line))
		return (-1);
	j = 0;
	find = 0;
	while (buf->buf[j])
	{
		(*line)[i++] = buf->buf[j];
		if (buf->buf[j++] == '\n')
		{
			find = 1;
			break ;
		}
	}
	(*line)[i] = 0;
	i = 0;
	while (buf->buf[j])
		buf->buf[i++] = buf->buf[j++];
	buf->buf[i] = 0;
	return (find);
}

char	*get_next_line(int fd)
{
	static t_buf	*head;
	t_buf			*buf;
	int				size;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (0);
	if (!head)
		head = ft_new_buf(fd);
	buf = ft_find_buf(fd, head);
	line = 0;
	if (ft_read_buf(buf, &line) > 0)
		return (line);
	size = read(fd, buf->buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf->buf[size] = 0;
		if (ft_read_buf(buf, &line) > 0)
			return (line);
		size = read(fd, buf->buf, BUFFER_SIZE);
	}
	if (line[0] != '\0')
		return (line);
	ft_clear_buf(fd, &head, &line);
	return (0);
}
