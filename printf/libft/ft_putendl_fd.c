/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayu <jayu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:19:18 by jayu              #+#    #+#             */
/*   Updated: 2021/12/10 22:29:33 by jayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	my_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	my_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

static void	my_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (my_isascii(s[i]))
			my_putchar_fd(s[i++], fd);
		else
			return ;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	my_putstr_fd(s, fd);
	my_putchar_fd('\n', fd);
}
