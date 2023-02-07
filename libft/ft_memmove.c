/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 08:11:52 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:48:47 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mp(unsigned char *dst, unsigned char *src, size_t i, size_t len)
{
	if (i == 0)
	{
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i != 0)
		{
			dst[i] = src[i];
			i--;
		}
		dst[0] = src[0];
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (dest <= source && src)
	{
		mp(dest, source, 0, len);
	}
	else if (len > 0 && dst)
	{
		mp(dest, source, len - 1, len);
	}	
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	*b = "0123456789ABCDEF\r\n";
	char	d[0xF0];
	char	g[0xF0];
//	unsigned char	*e;
//	unsigned char	*f;
	int	size;

	size = ft_strlen(b);
//	e = d + 2;
//	f = b + 2;
	char	*r1 = memmove(d, b, size);
	write(1, r1, size);
	char	*r2 = ft_memmove(g, b, size);
	write(1, r2, size);

//	r1 = memmove("", "" - 1, 0);
//	r2 = ft_memmove("", "" - 1, 0);
//	write(1, r1, size);
//	write(1, r2, size);

	r1 = memmove(NULL, NULL, 5);
	printf("%p\n", r1);
//	r2 = ft_memmove(NULL, NULL, 5);
//	printf("%p\n", r2);
//	write(1, r1, size);
//	write(1, r2, size);
//	printf("memcmp = %d\n", ft_memcmp(g,d,18));
//	printf("%s\n", b);
//	printf("%s\n", d);
	return (0);
}*/
