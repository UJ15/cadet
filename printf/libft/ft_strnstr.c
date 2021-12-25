/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:09:05 by jayu              #+#    #+#             */
/*   Updated: 2021/12/08 20:50:11 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cp;

	i = 0;
	cp = (char *)haystack;
	if (needle[i] == '\0')
		return (cp);
	while (i < len && cp[i] != '\0')
	{
		j = 0;
		if (cp[i] == needle[j])
		{
			while ((cp[i + j] == needle[j])
				&& (needle[j] != '\0') && (i + j < len))
				j++;
			if (needle[j] == '\0')
				return (&cp[i]);
		}
		i++;
	}
	return (0);
}
