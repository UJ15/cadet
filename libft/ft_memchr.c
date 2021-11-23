/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:31:33 by jayu              #+#    #+#             */
/*   Updated: 2021/11/22 11:43:03 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*tmp;

	tmp = (const char *)s;
	n++;
	while (*tmp != '\0' && --n > 0)
	{
		if (*tmp == c)
			return ((char *)tmp);
		tmp++;
	}
	return (NULL);
}
