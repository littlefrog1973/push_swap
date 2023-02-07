/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 05:52:16 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:48:27 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			i;

	source = (unsigned char *) src;
	destination = (unsigned char *) dst;
	i = 0;
	while (i < n && (dst || src))
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
//	unsigned char	b[10] = {1,1,1,1,1,1,1,1,1,1};
//	unsigned char	d[10] = {1,1,1,1,1,1,1,1,1,1};
//	unsigned char	*e;
//	unsigned char	c[10] = {'\0','\0','\0','\0','\0',5,5,5,5,5};
//	size_t	i;

//	e = NULL;
	ft_memcpy(NULL, NULL, 3);
//	memcpy(NULL, NULL, 3);
	for (i = 0; i < 10; i++)
	{
		printf("b[%lu] = %d\n", i, e[i]);
	}
	for (i = 0; i < 10; i++)
	{
		printf("d[%lu] = %d\n", i, d[i]);
	}
}*/
