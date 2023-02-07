/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:35:23 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:06:23 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_swap(char const *str)
{
	int		len;
	int		i;
	char	*output;

	len = (int) ft_strlen(str);
	output = (char *) ft_calloc(len + 1, 1);
	if (!output)
		return (NULL);
	if (len == 1)
		*output = *str;
	else
	{
		i = 0;
		while (i < len)
		{
			output[i] = str[len - 1 - i];
			i++;
		}
	}
	return (output);
}

char	*ft_itoa(int n)
{
	char		str[20];
	int			i;
	long int	nn;

	ft_bzero(str, 20);
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
	return (str_swap(str));
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("itoa = %s\n",ft_itoa(156));
	return (0);
}*/
