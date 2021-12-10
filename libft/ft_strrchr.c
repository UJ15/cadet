/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:12:33 by jayu              #+#    #+#             */
/*   Updated: 2021/12/10 21:18:19 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;
	int		i;

	i = 0;
	start = (char *)s;
	while (*start)
	{
		start++;
		i++;
	}
	if (c == 0)
		return (start);
	while (i >= 0)
	{
		if (*start == (char)c)
			return (start);
		else
		{
			i--;
			start--;
		}
	}
	return (0);
}
