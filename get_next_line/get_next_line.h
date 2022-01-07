/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:47:04 by jayu              #+#    #+#             */
/*   Updated: 2022/01/07 18:51:01 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_buf
{
	int				fd;
	char			*buf;
	struct s_buf	*next;
}			t_buf;

int		ft_buf_size(char *s);
t_buf	*ft_new_buf(int fd);
t_buf	*ft_find_buf(int fd, t_buf *buf);
int		ft_resize(int len, t_buf *buf, char **line);
void	ft_clear_buf(int fd, t_buf **head, char **line);
int		ft_strlen(char *s);
int		ft_read_buf(t_buf *buf, char **line);
char	*get_next_line(int fd);
int		get_line(int fd, t_buf *buf, char **line);

#endif
