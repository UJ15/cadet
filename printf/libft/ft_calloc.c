/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:14:52 by jayu              #+#    #+#             */
/*   Updated: 2021/11/23 13:48:38 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*my_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		*temp++ = c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = malloc(size * count);
	if (!arr)
		return (0);
	my_memset(arr, 0, size * count);
	return (arr);
}
