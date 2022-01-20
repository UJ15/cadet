/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:15:55 by jayu              #+#    #+#             */
/*   Updated: 2022/01/20 13:00:40 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int		str_len;
	int		flag;

	flag = 0;
	if (!str)
		str = "(null)";
	str_len = (int)ft_strlen(str);
	while (*str)
	{
		ft_putchar((char)*str);
		str++;
	}
	return (str_len);
}
