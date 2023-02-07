/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:08:00 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/06/01 16:39:03 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (!(c >= 0 && c <= 127))
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
	printf("ft_isascii = %d\n", ft_isascii(c));
	printf("isascii = %d\n", isascii(c));
	printf("ft_isascii = %d\n", ft_isascii(128));
	printf("isascii = %d\n", isascii(128));
}*/
