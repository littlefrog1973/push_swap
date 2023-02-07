/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 09:11:55 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:03:23 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*chr;
	size_t			i;

	chr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		chr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	b[10] = {1,1,1,1,1,1,1,1,1,1};
	char	d[10] = {1,1,1,1,1,1,1,1,1,1};
	size_t	i;

	ft_bzero(b, 10);
	bzero(d, 10);
	for (i = 0; i < 10; i++)
	{
		printf("b[%lu] = %d\n", i, b[i]);
	}
	for (i = 0; i < 10; i++)
	{
		printf("d[%lu] = %d\n", i, d[i]);
	}
}*/
