/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:17:51 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:49:06 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*chr;
	size_t			i;

	chr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		chr[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	b[10];
	char	d[10];
	size_t	i;

	ft_memset(b, 42, 10);
	memset(d, 42, 10);
	for (i = 0; i < 10; i++)
	{
		printf("b[%lu] = %d\n", i, b[i]);
	}
	for (i = 0; i < 10; i++)
	{
		printf("d[%lu] = %d\n", i, d[i]);
	}
}*/
