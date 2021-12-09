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
	t_list *l = ft_lstnew("a");
	printf("%s\n", (char *)l->content);
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew("b"));
	printf("%s\n", (char *)l->next->content);
	t_list *m = ft_lstmap(l, f, del);
	printf("%s\n", (char *)m->content);

	for(int i = 0; i < 4; i++)
	{
		printf("%s\n",(char *)m->content);
		m = m->next;
	}
}
