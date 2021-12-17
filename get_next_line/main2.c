//#include "gnlh.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct		s_buf
{
	int				fd;
	char			buf[10 + 1];
	struct s_buf	*next;
}					t_buf;

t_buf		*new_buf(int fd)
{
	t_buf *ret;

	if (!(ret = malloc(sizeof(t_buf))))
		return (0);
	ret->fd = fd;
	ret->buf[0] = 0;
	ret->next = 0;
	return (ret);
}

int main(void)
{

	char buf[10];

	

	int fd = open("./text2.txt", O_RDONLY);
	int c = read(3, buf, 5);
	printf("%s\n", buf);
	int l = read(3, buf, 3);
	printf("%s\n", buf);
}