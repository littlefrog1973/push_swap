/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:07:58 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:04:20 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	is_alpha;
	int	is_digit;

	is_alpha = ft_isalpha(c);
	is_digit = ft_isdigit(c);
	if (!(is_alpha || is_digit))
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
	char	alpha;
	char	digit;

	alpha = 'a';
	digit = '0';
	printf("ft_isalnum = %d\n", ft_isalnum(alpha)); 
	printf("isalnum = %d\n", isalnum(alpha)); 
	printf("ft_isalnum = %d\n", ft_isalnum(digit)); 
	printf("isalnum = %d\n", isalnum(digit));
}*/
