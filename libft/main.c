#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *c = "    -123";
	int k = 123;
	char *r = ft_itoa(k);

	printf("%s\n", r);
}
