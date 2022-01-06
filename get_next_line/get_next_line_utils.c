/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:46:35 by jayu              #+#    #+#             */
/*   Updated: 2022/01/06 15:23:38 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_buf_size(char *s)
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

t_buf	*ft_new_buf(int fd)
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

t_buf	*ft_find_buf(int fd, t_buf *buf)
{
	if (buf->fd == fd)
		return (buf);
	if (!buf->next)
	{
		buf->next = ft_new_buf(fd);
		return (buf->next);
	}
	return (ft_find_buf(fd, buf->next));
}

int	ft_resize(int len, t_buf *buf, char **line)
{
	int		i;
	int		j;
	char	*new_line;

	j = ft_buf_size(buf->buf);
	new_line = (char *)malloc(sizeof(char) * (len + j + 2));
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

void	ft_clear_buf(int fd, t_buf **head, char **line)
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
	cur = ft_find_buf(fd, *head);
	pre->next = cur->next;
	free(cur);
}
