/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:26:33 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/06/01 16:40:06 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (!(c >= ' ' && c <= '~'))
	{
		return (0);
	}
	return (1);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char c;

	c = '~';
	printf("ft_isprint = %d\n", ft_isprint(c));
	printf("isprint = %d\n", isprint(c));
	printf("ft_isprint = %d\n", ft_isprint(128));
	printf("isprint = %d\n", isprint(128));
}*/
