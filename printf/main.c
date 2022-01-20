#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int test(unsigned long long num)
{
	return num + 1;
}

int	main(void)
{
	int	i;
	
	i = 0;
	ft_printf("%s\n", NULL);
	printf("%s\n" , NULL);
}