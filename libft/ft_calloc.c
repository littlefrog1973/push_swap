/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:58 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/08/03 10:19:52 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0xffffffffffffffff || size == 0xffffffffffffffff)
		return (NULL);
	str = malloc(count * size);
	if (!str)
	{
		return ((void *) NULL);
	}
	ft_bzero(str, count * size);
	return (str);
}
/*
#include <unistd.h>
int	main(void)
{
//	char	*str1;
	char	*str2;
	int	i;

	printf("SIZE_MAX = %lu\n", SIZE_MAX);
//	str1 = (char *) ft_calloc(SIZE_MAX, 1);
//	if (!str1)
//		printf("ft_calloc cannot allocate\n");
	str2 = (char *) calloc(SIZE_MAX, 1);
	if (!str2)
		printf("calloc cannot allocate\n");
	i = 0;
	while (i < 10)
	{
		write(1, str1, 1);
		i++;
		str1++;
	}
	write(1, "\n", 1);
	while (i > 0)
	{
		write(1, str2,1);
		i--;
		str2++;
	}
	return (0);
}*/
