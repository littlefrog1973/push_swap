/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:46:02 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:02:48 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*find_digit(const char *str, int *sign, long int *base)
{
	int	i;

	i = 0;
	*base = 0;
	*sign = 1;
	while (ft_strchr(" \t\n\v\f\r", str[i]))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		*sign = 1 - 2 * (str[i] == '-');
		i++;
	}
	return (&str[i]);
}

int	ft_atoi(const char *str)
{
	long int	base;
	int			sign;

	if (!(*str) || !str)
		return (0);
	str = find_digit(str, &sign, &base);
	while (*str >= '0' && *str <= '9')
	{
		if (base == 9223372036854775807 / 10 && *str >= '7' && sign == 1)
			return (-1);
		else if (base == 9223372036854775807 / 10 && *str >= '8' && sign == -1)
			return (0);
		else if (base > 9223372036854775807 / 10)
			return (-(sign == 1));
		else
			base = base * 10 + *str - '0';
		str++;
	}
	return ((int) base * sign);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
//	char	str[] = "9223372036854775809";
//	char	str[] = "-9323372036854775808";
	char	str[] = "";
//	char	str[] = "4611686018427387905";
//	char	str[] = "2147483648";
//	char	str[] = "2720202020";

	printf("int of str (atoi) = %d\n", atoi(str));
	printf("int of str (ft_atoi) = %d\n", ft_atoi(str));
//	printf("LONG_MAX = %ld\n",LONG_MAX);
//	printf("LONG_MIN = %ld\n",LONG_MIN);
	return (0);
}*/
