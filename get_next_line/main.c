//#include "get_next_line.h"
#include "gnlh.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	int		i;
	int		j;
	char	*line = 0;

	fd = open("./text.txt", O_RDONLY);

	j = 1;
	if (!fd)
	{
		printf("\nERROR in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	printf("%d\n", j);

	if (i == -1)
		printf("\nError Function\n");
	else if (j == 2)
		printf("\ngood!\n");
	else if (j != 2)
		printf("\nfuck!\n");
}
