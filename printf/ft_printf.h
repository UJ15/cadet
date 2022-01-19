/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:27:59 by jayu              #+#    #+#             */
/*   Updated: 2022/01/19 15:26:10 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define TYPE "cspdiuxX%"

typedef struct s_property
{
	char	type;
	int		sign;
	int		base;
}			t_property;

int		ft_printf(const char *fmt, ...);
int		read_format(va_list argp, char *fmt);
void	init_prop(t_property *prop);
int		ft_putchar(int c);
int		print_format_type(va_list argp, t_property *prop);
int		print_str(char *str, t_property *prop);
int		print_nbr(unsigned long long nbr, t_property *prop, char *base);
int		print_char(int c, t_property *prop);
int		ft_putstr(char *str);
void	check_nbr(char **str, t_property *prop);
char	*ft_ntoa(unsigned long long nbr, t_property *prop,
			char *base, int result_len);
int		ft_nbrlen(unsigned long long nbr, t_property *prop);

#endif
