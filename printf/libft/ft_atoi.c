/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:37:22 by jayu              #+#    #+#             */
/*   Updated: 2021/12/11 00:18:13 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	my_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long			sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while (my_is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (result > LLONG_MAX - 1 && sign == -1)
			return (0);
		else if (result > LLONG_MAX && sign == 1)
			return (-1);
		else
			result = result * 10 + (*str - 48);
		str++;
	}
	return (result * sign);
}
