/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:23:43 by jayu              #+#    #+#             */
/*   Updated: 2021/12/19 14:24:43 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

int	read_buf(t_buf *buf, char **line)
{
	int	i;
	int	j;
	int	find;

	i = ft_strlen(*line);
	if (!resize(i, buf, line))
		return (-1);
	j = 0;
	find = 0;
	while (buf->buf[j])
	{
		(*line)[i++] = buf->buf[j];
		if (buf-> buf[j++] == '\n')
		{
			i--;
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

int	get_next_line(int fd, char **line)
{
	static t_buf	*head;
	t_buf			*buf;
	int				find;
	int				size;

	if (!head)
		head = new_buf(fd);
	buf = find_buf(fd, head);
	if (BUFFER_SIZE < 0 || fd < 0 || !buf)
		return (-1);
	*line = 0;
	find = read_buf(buf, line);
	if (find > 0)
		return (find);
	size = read(fd, buf->buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf->buf[size] = 0;
		find = read_buf(buf, line);
		if (find > 0)
			return (find);
		size = read(fd, buf->buf, BUFFER_SIZE);
	}
	clear_buf(fd, &head);
	return (size);
}
