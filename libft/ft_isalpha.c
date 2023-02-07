/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:30:42 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/06/01 14:53:23 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{	
	int	is_lower;
	int	is_upper;

	is_lower = 0;
	is_upper = 0;
	if (c >= 'a' && c <= 'z')
	{
		is_lower = 1;
	}
	if (c >= 'A' && c <= 'Z')
	{
		is_upper = 1;
	}
	if (!(is_lower || is_upper))
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
	char	c;

	c = '\b';
	printf("ft_isalpha = %d\n", ft_isalpha(c));
	printf("is_alpha = %d\n", isalpha(c));
}*/
