/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:56:04 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/06/01 15:05:52 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
	{
		return (0);
	}
	return (1);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
//	char	c1 = '0';
	char	c2 = 'a';

	printf("ft_isdigit = %d\n",ft_isdigit(c2));
	printf("isdigit = %d\n",isdigit(c2));
}*/
