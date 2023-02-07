/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:12:21 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:57:56 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		cmp;
	size_t	i;
	size_t	k;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	k = 0;
	while (k < n && k <= i)
	{
		cmp = (unsigned char) s1[k] - (unsigned char) s2[k];
		if (cmp)
		{
			return (cmp);
		}
		k++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	str1[] = "test\200";
	char	str2[] = "test\0";
	int	cmp1;
	int	cmp2;

	cmp1 = strncmp(str1, str2, 6);
	printf("%d\n", cmp1);
	cmp2 = ft_strncmp(str1, str2, 6);
	printf("%d", cmp2);
	return (0);
}*/
