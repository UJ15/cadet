/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:15:55 by jayu              #+#    #+#             */
/*   Updated: 2022/01/19 16:08:30 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, t_property *prop)
{
	int	str_len;

	str_len = (int)ft_strlen(str);
	while (*str)
	{
		ft_putchar((char)*str);
		str++;
	}
	return (str_len);
}
