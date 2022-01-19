/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:26:33 by jayu              #+#    #+#             */
/*   Updated: 2022/01/19 15:56:30 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

void	init_prop(t_property *prop)
{
	prop->base = 10;
	prop->sign = 0;
	prop->type = 0;
}

int	print_format_type(va_list argp, t_property *prop)
{
	int	result;

	result = 0;
	if (prop->type == 'c')
		result = print_char(va_arg(argp, int), prop);
	else if (prop->type == '%')
		result = print_char(prop->type, prop);
	else if (prop->type == 's')
		result = print_str(va_arg(argp, char *), prop);
	else if (prop->type == 'p')
		result = print_nbr(va_arg(argp, unsigned long long), prop,
				"0123456789abcdef");
	else if (prop->type == 'd')
		result = print_nbr(va_arg(argp, int), prop, "0123456789");
	else if (prop->type == 'i')
		result = print_nbr(va_arg(argp, int), prop, "0123456789");
	else if (prop->type == 'u')
		result = print_nbr(va_arg(argp, unsigned int), prop, "0123456789");
	else if (prop->type == 'x')
		result = print_nbr(va_arg(argp, unsigned int), prop,
				"0123456789abcdef");
	else if (prop->type == 'X')
		result = print_nbr(va_arg(argp, unsigned int), prop,
				"0123456789ABCDEF");
	return (result);
}

int	read_format(va_list argp, char *format)
{
	int			result;
	t_property	*prop;

	result = 0;
	prop = malloc(sizeof(t_property));
	if (!prop)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			init_prop(prop);
			format++;
			if (ft_strchr(TYPE, (char)*format))
				prop->type = *format++;
			if (prop->type == 'p' || prop->type == 'x' || prop->type == 'X')
				prop->base = 16;
			result += print_format_type(argp, prop);
		}
		else
			result += ft_putchar(*format++);
	}
	free(prop);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	argp;

	va_start(argp, format);
	result = read_format(argp, (char *)format);
	va_end(argp);
	return (result);
}
