/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:22:54 by jayu              #+#    #+#             */
/*   Updated: 2021/11/25 17:27:04 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	my_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

static void	my_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

static void	my_putnb(int n, int fd)
{
	if (n >= 10)
	{
		my_putnb(n / 10, fd);
		my_putchar_fd('0' + (n % 10), fd);
	}
	else
		my_putchar_fd('0' + n, fd);
}

void	my_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i] != '\0')
	{
		if (my_isascii(s[i]))
			my_putchar_fd(s[i++], fd);
		else
			return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		my_putstr_fd("-2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		n *= -1;
		my_putchar_fd('-', fd);
	}
	my_putnb(n, fd);
}
