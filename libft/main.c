#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <stdlib.h>


void	*f(void *c)
{
	return "x";
}

void	del(void *c)
{
	c += 1;
}
int main(void)
{
	char **c = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	int i = 0;
	while (c[i] != NULL)
	{
		printf("%s\n", c[i]);
		i++;
	}
	
}
