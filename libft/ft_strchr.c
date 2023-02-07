/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:24:13 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/16 22:46:56 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	cc;

	str = (char *) s;
	cc = (char) c;
	while (*str)
	{
		if (*str == cc)
		{
			return (str);
		}
		str++;
	}
	if (!c)
	{
		return (str);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int	main(void)
{
	char	str1[] = "tripouille";
	char	*c;	
	char	*d;	
	char	e;

	write(1, str1, 10);
	write(1, "\n", 1);
	e = (char) 't' + 256;
	printf("t+256 = %d\n", e);
	c = ft_strchr(str1, 't' + 256);
	printf("return = %s\n", c);
	d = strchr(str1, 't' + 256);
	printf("return = %s\n", d);
	return (0);
}*/
