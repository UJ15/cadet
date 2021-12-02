/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:12:33 by jayu              #+#    #+#             */
/*   Updated: 2021/12/02 21:29:05 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*s)
		s++;
	if (!c)
		return ((char *)s);
	while (s != start)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
