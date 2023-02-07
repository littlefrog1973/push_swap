/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 06:19:44 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:55:09 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1)
		{	
			if (i < j)
			{
				dst[i] = src[i];
			}
			else if (i == j && dst[i] != '\0')
			{
				dst[i] = '\0';
				return (j);
			}
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}	
/*	
#include <unistd.h>
#include <string.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	src[] = "0123456789";
	char	dest[] = "abcdefghijk";
	char	dest2[] = "abcdefghijk";
	unsigned int	n;
	unsigned int	i;

	n = 10;
	for (i = 0; i < 12; i++) ft_putchar(dest[i]);
	ft_putchar('\n');
	printf("%lu\n",strlcpy(dest, src, n));
	for (i = 0; i < 12; i++) ft_putchar(dest[i]);
	ft_putchar('\n');
	printf("%lu\n",ft_strlcpy(dest2, src, n));
	for (i = 0; i < 12; i++) ft_putchar(dest2[i]);
	ft_putchar('\n');
	return (0);
}*/
