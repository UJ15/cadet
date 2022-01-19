#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

int	main(void)
{
	int	i;
	char *t = "qwe";

	i = -2232;
	ft_printf("---my printf---\ns : %s\nd : %d\nx : %x\np : %p\n\n", t, i, i, &i);
	printf("---lib printf---\ns : %s\nd : %d\nx : %x\np : %p\n", t, i, i, &i);
}
