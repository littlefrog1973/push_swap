/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:10:51 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:50:53 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static	void	put_out(int fd, char *str, int len)
{
	int	i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
		{
			write(fd, (str + len - 1 - i), 1);
			i++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		str[20];
	int			i;
	long int	nn;

	i = 0;
	while (i < 20)
		str[i++] = '\0';
	nn = (long) n;
	i = 0;
	if (nn == 0)
		str[i++] = '0';
	else
	{
		while (nn != 0 && i < 20)
		{
			if (nn > 0)
				str[i++] = nn % 10 + '0';
			else
				str[i++] = -nn % 10 + '0';
			nn = nn / 10;
		}
		if (n < 0)
			str[i++] = '-';
	}
	put_out(fd, str, i);
}
/*
#include <limits.h>

int	main(void)
{
	int	fd;
	int	n;

	n = 0;
	fd = 1;
	ft_putnbr_fd(INT_MAX, fd);
	write(1, "\n", fd);
}*/
