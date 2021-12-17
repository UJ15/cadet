/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:06 by jayu              #+#    #+#             */
/*   Updated: 2021/12/17 21:21:07 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	buf_size(char *s)
{
	int ret;

	if (!s || *s == '\n')
		return (0);
	ret = 0;
	while (*s && *s != '\n')
	{
		ret++;
		s++;
	}
	return (ret);
}

int	read_buf(t_buf *buf, char **line)
{
	int	i;
	int	j;
	int	find;

	i = ft_strlen(*line);
	printf("line_len = %d\n", i);
	if(!(resize(i, buf, line)))
		return (-1);
	j = 0;
	find = 0;
	while (buf->buf[j])
	{
		(*line)[i++] = buf->buf[j];
		if (buf->buf[j++] == '\n')
		{
			i--;
			find = 1;
			break;
		}
		printf("line = %s\n", *line);
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
	if (BUFFER_SIZE < 0 || fd < 0)
		return (-1);
	*line = 0;
	printf("head2 = %s\n", head->buf);
	find = read_buf(buf, line);
	if (find > 0)
		return (find);
	size = read(fd, buf->buf, BUFFER_SIZE);
	while (size > 0)
	{
		printf("head1 = %s\n", head->buf);
		buf->buf[size] = 0;
		find = read_buf(buf, line);
		if (find > 0)
			return (find);
		size = read(fd, buf->buf, BUFFER_SIZE);
	}
	clear_buf(fd, &head);
	return (size);
}
 