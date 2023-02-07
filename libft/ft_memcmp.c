/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:28:56 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:48:04 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{	
	int	cmp;

	while (n > 0)
	{
		cmp = *(unsigned char *) s1 - *(unsigned char *) s2;
		if (cmp)
		{
			return (cmp);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[] = "abcdf";
	char	str2[] = "hijkl";
	int	cmp1;
	int	cmp2;

	cmp1 = memcmp(str1, str2, 3);
	printf("%d\n", cmp1);
	cmp2 = ft_memcmp(str1, str2, 3);
	printf("%d\n", cmp2);
	return (0);
}*/
