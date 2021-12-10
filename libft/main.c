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
	t_list *head = ft_lstnew("a");
	t_list *n1 = ft_lstnew("b");
	head->next = n1;
	t_list *n2 = ft_lstnew("c");
	n1->next = n2;
	t_list *cp = ft_lstmap(head, f, del);
	while(head)
	{
		printf("%s\n", head->content);
		head=head->next;
	}
	while(cp)
	{
		printf("%s\n", cp->content);
		cp=cp->next;
	}
}
