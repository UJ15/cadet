/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:14:48 by jayu              #+#    #+#             */
/*   Updated: 2021/11/21 19:08:57 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	my_strnlen(char *s, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n && s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static void	*my_memcpy(void *dst, const void *src, size_t n)
{
	char		*to;
	const char	*from;

	to = (char *)dst;
	from = (const char *)src;
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;

	dstlen = my_strnlen(dst, dstsize);
	if (dstsize == dstlen)
		return (dstlen + my_strlen(src));
	return (dstlen + my_strlcpy(dst + dstlen, src, dstsize - dstlen));
}
