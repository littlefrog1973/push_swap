/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 06:52:36 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:57:33 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*target;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	target = (char *) malloc(len + 1);
	if (!target)
		return ((char *) NULL);
	i = 0;
	while (i < len + 1)
	{
		target[i] = '\0';
		i++;
	}
	i = 0;
	while (s[i])
	{
		target[i] = f(i, s[i]);
		i++;
	}
	return (target);
}
