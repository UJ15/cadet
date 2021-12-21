#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int		fd;
	int		i;
	int		j;
	char *line;

	fd = open("./text.txt", O_RDONLY);

	j = 1;
	if (!fd)
	{
		printf("\nERROR in open\n");
		return (0);
	}
	while((line = get_next_line(fd)) != 0)
	{
		printf("%s",  line);
	}
//	printf("%s", line);
	free(line);
	close(fd);
}
