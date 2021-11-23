/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:20:09 by jayu              #+#    #+#             */
/*   Updated: 2021/11/23 16:53:35 by jayu             ###   ########.fr       */
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

static char	*my_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (0);
}

static void	*my_memcpy(void *dst, const void *src, size_t n)
{
	char		*to;
	const char	*from;

	to = dst;
	from = src;
	while (n-- > 0)
	{
		*to++ = *from++;
	}
	return (dst);
}

static size_t	my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = my_strlen(src);
	if (srclen + 1 < dstsize)
		my_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		my_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cp;
	int		start;
	int		end;

	start = 0;
	end = my_strlen(s1);
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	while (s1[start] && my_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && my_strchr(set, s1[end - 1]))
	{
		if (end - 1 < 1)
			break ;
		end--;
	}
	if (start >= end)
		return ("");
	cp = (char *)malloc(sizeof(char) * (end - start) + 1);
	my_strlcpy(cp, &s1[start], end - start + 1);
	return (cp);
}
