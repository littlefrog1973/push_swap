/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:17:17 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/12/19 17:12:02 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	putunbr(unsigned int n, int fd)
{
	char		str[20];
	int			i;

	i = 0;
	while (i < 20)
		str[i++] = '\0';
	i = 0;
	if (n == 0)
		str[i++] = '0';
	else
	{
		while (n != 0 && i < 20)
		{
			str[i++] = n % 10 + '0';
			n = n / 10;
		}
	}
	put_out(fd, str, i);
	return (i);
}
