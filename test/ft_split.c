/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:53:54 by jayu              #+#    #+#             */
/*   Updated: 2021/12/08 22:00:41 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	my_word_cnt(char const *s, char c)
{
	int	cnt;

	if (!s)
		return (-2);
	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cnt);
}

static char	**my_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	result = 0;
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
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	srclen = i;
	if (srclen + 1 < dstsize)
		my_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		my_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*start;
	int		i;

	result = (char **)malloc(sizeof(char *) * (my_word_cnt(s, c)) +  1);
	if (!result)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			result[i] = (char *)malloc(sizeof(char) * (s - start) + 1);
			if (!result[i])
				return (my_free(result));
			my_strlcpy(result[i++], start, (s - start + 1));
		}
		else
			s++;
	}
	return (result);
}

int main(void)
{
	char *s = "abcabacabacababcacacacbacbacbacbacbabcabcabcabcbacabcvacabcbacbacbabcabcbacbabcabcbacbabcabcabcbc";
	char **r = ft_split(s, 'c');
	int i = 0;

	while (r[i] != NULL)
	{
		printf("%s\n", r[i]);
		i++;
	}
}
