/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:22:42 by jayu              #+#    #+#             */
/*   Updated: 2021/11/23 15:53:14 by jayu             ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cp;
	int		size;

	if (!s)
		return (0);
	cp = (char *)malloc(sizeof(char *) * len + 1);
	if (!cp)
		return (0);
	size = my_strlen(s);
	if (size <= start)
	{
		*cp = 0;
		return (cp);
	}
	my_strlcpy(cp, s + start, len + 1);
	return (cp);
}
