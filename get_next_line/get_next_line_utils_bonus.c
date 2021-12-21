/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:46:35 by jayu              #+#    #+#             */
/*   Updated: 2021/12/21 13:09:41 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	buf_size(char *s)
{
	int	i;

	if (!s || *s == '\n')
		return (0);
	i = 0;
	while (*s && *s != '\n')
	{
		s++;
		i++;
	}
	return (i);
}

t_buf	*new_buf(int fd)
{
	t_buf	*new;

	new = (t_buf *)malloc(sizeof(t_buf));
	if (!new)
		return (0);
	new->fd = fd;
	new->buf[0] = 0;
	new->next = 0;
	return (new);
}

t_buf	*find_buf(int fd, t_buf *buf)
{
	if (buf->fd == fd)
		return (buf);
	if (!buf->next)
	{
		buf->next = new_buf(fd);
		return (buf->next);
	}
	return (find_buf(fd, buf->next));
}

int	resize(int len, t_buf *buf, char **line)
{
	int		i;
	int		j;
	char	*new_line;

	j = buf_size(buf->buf);
	new_line = (char *)malloc(sizeof(char) * (len + j + 1));
	if (!new_line)
		return (0);
	i = 0;
	while (i < len)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	new_line[i] = 0;
	free(*line);
	*line = new_line;
	return (1);
}

void	clear_buf(int fd, t_buf **head, char **line)
{
	t_buf	*pre;
	t_buf	*cur;
	char	*temp;

	pre = *head;
	temp = *line;
	free(temp);
	if (pre->fd == fd)
	{
		cur = pre->next;
		free(pre);
		*head = cur;
		return ;
	}
	while (pre->next->fd != fd)
		pre = pre->next;
	cur = find_buf(fd, *head);
	pre->next = cur->next;
	free(cur);
}