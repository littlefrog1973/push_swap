/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:17:56 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/12/19 17:11:41 by sdeeyien         ###   ########.fr       */
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

int	putptr(void *ptr, int fd)
{
	char		str[20];
	int			i;
	size_t		rem;

	i = 0;
	while (i < 20)
		str[i++] = '\0';
	i = 0;
	if (ptr == NULL)
		i = (int) ft_strlcpy(str, NULL_PTR, sizeof(NULL_PTR) + 1);
	else
	{
		rem = (size_t) ptr;
		while (rem)
		{
			str[i] = (rem & 15) + '0';
			if (str[i] > '9')
				str[i] = str[i] - ('9' + 1) + 'a';
			rem = rem >> 4;
			i++;
		}
		i += (int) ft_strlcpy(&str[i], "x0", sizeof("x0") + 1);
	}
	put_out(fd, str, i);
	return (i);
}
