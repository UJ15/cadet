/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:22:42 by jayu              #+#    #+#             */
/*   Updated: 2021/12/09 17:20:13 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*cp;

	i = -1;
	j = 0;
	if (!s)
		return (0);
	cp = malloc(len + 1);
	if (!cp)
		return (0);
	while (s[++i] != '\0')
		if (i >= start && j < len)
			cp[j++] = s[i];
	cp[j] = '\0';
	return (cp);
}
