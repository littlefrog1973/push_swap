/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:38:56 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:59:25 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	sub_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start + len > s_len)
	{
		if (start > s_len)
			sub_len = 0;
		else
			sub_len = s_len - start;
	}
	else
		sub_len = len;
	substr = (char *) malloc(sub_len + 1);
	if (!substr)
		return ((char *) NULL);
	ft_memcpy((void *) substr, (void *)(s + start), sub_len);
	substr[sub_len] = '\0';
	return (substr);
}
/*
//	ft_memcpy((void *) substr, (void *)(s + start), sub_len);
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int	main(void)
{
	char	str[] = "I just want this part #############";
	size_t	size = 20;

	char *ret = ft_substr(str, 5, size);
	str[size + 5] = 0;
	write(1, ret, 21);
	write(1, "\n", 1);
	write(1, &str[5],21);
	printf("\nmemcmp = %d", memcmp(ret, str + 5, size + 1));
//	printf("ret  = %s\n", ret);
//	printf("str  = %s\n", &str[5]);
	return (0);
}


int	main(void)
{
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr(str, 10, size);

	if (!strncmp(ret, "", 1))
		printf("success\n");
	else
		printf("failed\n");
}*/
