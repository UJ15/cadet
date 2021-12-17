/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:46:35 by jayu              #+#    #+#             */
/*   Updated: 2021/12/17 20:57:46 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *s)
{
	int ret;

	if (!s)
		return (0);
	ret = 0;
	while (*s++)
		ret++;
	return (ret);
}

t_buf	*new_buf(int fd)
{
	t_buf	*new;
	
	new = malloc(sizeof(t_buf));
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
	if (!(buf->next))
		return (buf->next = new_buf(fd));
	return (find_buf(fd, buf->next));
}

int	resize(int len, t_buf *buf, char **line)
{
	char	*new_line;
	int		j;
	int		i;

	j = buf_size(buf->buf);
	new_line = malloc(len + j + 1);
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

void	clear_buf(int fd, t_buf **head)
{
	t_buf	*pre;
	t_buf	*curr;

	pre = *head;
	if (pre->fd == fd)
	{
		curr = pre->next;
		free(pre);
		*head = curr;
		return ;
	}
	while (pre->next->fd != fd)
		pre = pre->next;
	curr = find_buf(fd, *head);
	pre->next = curr->next;
	free(curr);
}



