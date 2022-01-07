/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:23:43 by jayu              #+#    #+#             */
/*   Updated: 2022/01/07 19:06:06 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	if (!head)
		head = ft_new_buf(fd);
	buf = ft_find_buf(fd, head);
	line = 0;
	if(buf->buf == 0)
	{
		buf->buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		buf->buf[0] = 0;
	}
	if (get_line(fd, buf, &line) > 0)
		return (line);
	if (line[0] != '\0' && line != 0)
		return (line);
	free(buf->buf);
	ft_clear_buf(fd, &head, &line);
	return (0);
}

int	get_line(int fd, t_buf *buf, char **line)
{
	int	size;

	if (ft_read_buf(buf, line) > 0)
		return (1);
	size = read(fd, buf->buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf->buf[size] = 0;
		if (ft_read_buf(buf, line) > 0)
			return (1);
		size = read(fd, buf->buf, BUFFER_SIZE);
	}
	return (0);
}

