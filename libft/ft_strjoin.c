/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:29:20 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:54:23 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	str_join = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str_join)
		return (NULL);
	ft_strlcpy(str_join, (char *) s1, ft_strlen(s1) + 1);
	ft_strlcat(str_join, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (str_join);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "def";

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("s1 + s2 = %s\n", ft_strjoin(s1, s2));
	return (0);
}*/
