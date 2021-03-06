/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:49:21 by jayu              #+#    #+#             */
/*   Updated: 2021/12/10 21:17:56 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cp;

	cp = (char *)s;
	while (*cp)
	{
		if (*cp == (char)c)
			return (cp);
		else
			cp++;
	}
	if (*cp == c)
		return (cp);
	return (0);
}
