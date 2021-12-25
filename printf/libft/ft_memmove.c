/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:26:54 by jayu              #+#    #+#             */
/*   Updated: 2021/11/23 12:16:43 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*to;
	const char	*from;
	size_t		i;

	to = dst;
	from = src;
	i = -1;
	if (dst == src || len == 0)
		return (dst);
	if (to > from)
	{
		while (++i < len)
		{
			to[len - 1 - i] = from[len - 1 - i];
		}
	}
	else
	{
		while (++i < len)
		{
			to[i] = from[i];
		}
	}
	return (dst);
}
