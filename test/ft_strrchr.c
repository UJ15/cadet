/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:12:33 by jayu              #+#    #+#             */
/*   Updated: 2021/12/02 21:08:44 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	if (!*s)
		return (0);
	start = (char *)s;
	while (*s)
		s++;
	if (!c)
		return ((char *)s);
	while (--s != start)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
	}
	return (0);
}

int main(void)
{
	char *s = "qweasds";
	
	char *co = strrchr(s, 0);
	char *my = ft_strrchr(s, 0);

	printf("my %s\nre %s\n", my, co);
}
