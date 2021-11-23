/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:13 by jayu              #+#    #+#             */
/*   Updated: 2021/11/23 19:18:20 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	my_strlen(const char *s)
{	
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*cp;
	int		size;
	int		i;

	i = 0;
	size = my_strlen(s1);
	cp = (char *)malloc(sizeof(char) * size + 1);
	if (!cp)
		return (0);
	while (i < size)
	{
		cp[i] = s1[i];
		i++;
	}
	cp[size] = '\0';
	return (cp);
}
