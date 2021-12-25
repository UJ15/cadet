/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:17:26 by jayu              #+#    #+#             */
/*   Updated: 2021/12/10 22:21:57 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	num_len(int num)
{
	size_t		cnt;
	long long	n;

	n = num;
	cnt = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	trans(char *result, int num, int len)
{
	long long	n;

	n = num;
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	if (n >= 10)
	{
		trans(result, (n / 10), --len);
		result[len] = (n % 10) + '0';
	}
	else
		result[--len] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;

	len = num_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	trans(result, n, len);
	result[len] = '\0';
	return (result);
}
