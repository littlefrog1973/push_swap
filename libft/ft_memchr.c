/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:44:05 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:47:41 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*str;

	cc = (unsigned char) c;
	str = (unsigned char *) s;
	while (n > 0)
	{
		if (*str == cc)
		{
			return ((void *) str);
		}
		str++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int	main(void)
{
//	char	str1[10] = "abcde\128fghij";
	unsigned char	str1[10] = {97,98,99,100,101,102,103,104,105,106};
	unsigned char	*c;	
	unsigned char	*d;	

	write(1, str1, 10);
	write(1, "\n", 1);
	d = memchr(str1, 300, 10);
	printf("return = %s\n", d);
	c = ft_memchr(str1, 300, 10);
	printf("return = %s\n", c);
	return (0);
}*/
