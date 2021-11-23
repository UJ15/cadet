/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:09:05 by jayu              #+#    #+#             */
/*   Updated: 2021/11/23 12:16:28 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	tmp;

	i = 0;
	while (i < len || haystack[i] != '\0')
	{
		tmp = 0;
		if (haystack[i + tmp] == needle[tmp])
		{
			while (haystack[i + tmp] != '\0' && needle[tmp] != '\0')
			{
				if (haystack[i + tmp] != needle[tmp] || i + tmp >= len)
					break ;
				tmp++;
			}
			if (needle[tmp] == '\0')
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (0);
}
