/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:23:42 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:59:03 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	size_t	begin;
	size_t	end;

	if ((!(s1) || !(set)) || (!(*s1)))
		return (ft_strdup(""));
	begin = 0;
	end = ft_strlen(s1);
	if (end > 0)
		end--;
	while (ft_strchr(set, s1[begin]) && s1[begin])
		begin++;
	while (ft_strchr(set, s1[end]) && end != 0)
		end--;
	if (end >= begin && !ft_strchr(set, s1[begin]))
	{
		str_trim = (char *) malloc((end - begin + 2) * sizeof(char));
		if (!str_trim)
			return (NULL);
		ft_bzero(str_trim, (end - begin + 2) * sizeof(char));
		ft_memcpy(str_trim, s1 + begin, end - begin + 1);
	}
	else
		return (ft_strdup(""));
	return (str_trim);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
//	char	s1[] = "lorel ipsum dolor sit amet \n t";
//	char	s1[] = "  \t \t \n  \n\n\n\t";
	char	s1[] = "      ";
//	char	s4[] = " ";
//	char	s2[] = "";
	char	*s3;

//char *ret = ft_strtrim(s1, "");

	printf("ft_strlen = %lu\n",ft_strlen("") - 1);
	s3 = ft_strtrim(s1, " ");
//	printf("%s\n", s1);
	printf("In main:%s\n", s3);
//	printf("strcmp result = %d\n",strcmp(s3,s2));
	return (0);
}

int	main(void)
{
//	char	s1[] = "lorel ipsum dolor sit amet \n t";
	char	s1[] = "";
//	char	s2[] = "\n \t";
	char	s2[] = "";
	char	*s3;

	s3 = ft_strtrim(s1, " \n\t");
//	printf("%s\n", s1);
	printf("In main: %p\n", s3);
	printf("strcmp result = %d\n",strcmp(s3,s2));
	return (0);
}
*/
