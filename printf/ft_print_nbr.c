/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:46:48 by jayu              #+#    #+#             */
/*   Updated: 2022/01/20 12:43:21 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(unsigned long long nbr, t_property *prop)
{
	int	result;

	result = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		result++;
		nbr = nbr / prop->base;
	}
	return (result);
}

char	*ft_ntoa(unsigned long long nbr, t_property *prop,
					char *base, int result_len)
{
	char	*result;

	result = malloc(sizeof(char) * result_len + 1);
	if (!result)
		return (0);
	result[result_len] = '\0';
	while (--result_len >= 0)
	{
		result[result_len] = base[nbr % prop->base];
		nbr /= prop->base;
	}
	return (result);
}

void	check_nbr(char **str, t_property *prop)
{
	if (prop->sign == 1)
		*str = ft_strjoin("-", *str, 2);
	if (prop->type == 'p')
		*str = ft_strjoin("0x", *str, 2);
}

int	ft_putstr(char *str)
{
	int	result;

	result = 0;
	while (*str)
	{
		write(1, str, 1);
		result++;
		str++;
	}
	return (result);
}

int	print_nbr(unsigned long long nbr, t_property *prop, char *base)
{
	int		result;
	char	*str;
	int		result_len;

	result = 0;
	if ((prop->type == 'i' || prop->type == 'd') && (int)nbr < 0)
	{
		prop->sign = 1;
		nbr *= -1;
	}
	result_len = ft_nbrlen(nbr, prop);
	str = ft_ntoa(nbr, prop, base, result_len);
	check_nbr(&str, prop);
	result = ft_putstr(str);
	free(str);
	return (result);
}
