/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:08:44 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/06 10:22:55 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r'
		|| c == '\v')
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("ft_isspace(' ') =%d\n", ft_isspace(' '));
	printf("ft_isspace('\\t') =%d\n", ft_isspace('\t'));
	printf("ft_isspace('\\n') =%d\n", ft_isspace('\n'));
	printf("ft_isspace('\\r') =%d\n", ft_isspace('\r'));
	printf("ft_isspace('\\v') =%d\n", ft_isspace('\v'));
	printf("ft_isspace('\\f') =%d\n", ft_isspace('\f'));
	printf("ft_isspace('a') =%d\n", ft_isspace('a'));
}
*/
