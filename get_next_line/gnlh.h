#ifndef GNLH_H
# define GNLH_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

typedef struct		s_buf
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	struct s_buf	*next;
}					t_buf;

size_t				size_check(const char *s);
size_t				ft_strlen(const char *s);
t_buf				*new_buf(int fd);
t_buf				*find_buf(int fd, t_buf *buf);
int					read_buf(t_buf *buf, char **line);
void				erase_buf(int fd, t_buf **head);
int					resize(size_t len, t_buf *buf, char **line);
int					get_next_line(int fd, char **line);

#endif