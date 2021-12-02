/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:09:54 by jayu              #+#    #+#             */
/*   Updated: 2021/12/02 20:07:55 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (cp1[i] == cp2[i] && cp1[i] != '\0' && cp2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return (cp1[i] - cp2[i]);
}
