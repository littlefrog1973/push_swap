/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:18:33 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/12/19 17:11:16 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	put_out(int fd, char *str, int len)
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
	return (len);
}

int	puthex(int n, int fd, const char *hexi, unsigned int flag)
{
	int				i;
	char			str[20];
	unsigned int	rem;

	ft_bzero(str, 20);
	i = 0;
	if (n == 0)
		str[i++] = '0';
	else
	{
		rem = (unsigned) n;
		while (rem)
		{
			str[i] = (rem & 15) + '0';
			if (str[i] > '9')
				str[i] = str[i] - ('9' + 1) + 'A' + *hexi - 'X';
			rem = rem >> 4;
			i++;
		}
	}
	if ((flag & 0x0F00) && (n != 0) && (*hexi - 'X'))
		i = ft_strlcat(str, "x0", sizeof("x0") + ft_strlen(str));
	else if ((flag & 0x0F00) && n != 0 && *hexi == 'X')
		i = ft_strlcat(str, "X0", sizeof("X0") + ft_strlen(str));
	return (put_out(fd, str, i));
}
