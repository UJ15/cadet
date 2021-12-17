/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:47:04 by jayu              #+#    #+#             */
/*   Updated: 2021/12/17 20:57:45 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct  s_buf
{
    int             fd;
    char            buf[BUFFER_SIZE + 1];
    struct s_buf    *next;
}               t_buf;

t_buf   *new_buf(int fd);
t_buf   *find_buf(int fd, t_buf *buf);
int     get_next_line(int fd, char **line);
int	    read_buf(t_buf *buf, char **line);
int	    resize(int len, t_buf *buf, char **line);
void	clear_buf(int fd, t_buf **head);
int	    buf_size(char *s);
int     ft_strlen(char *s);

#endif 