/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:17:37 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/12/19 17:11:52 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	putstr(char *s, int fd, unsigned int flag)
{
	if (s)
	{
		if ((flag & 0x00F0) && *s)
		{
			write(fd, s, ft_strlen(s));
			return (ft_strlen(s));
		}
		write(fd, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	else
	{
		write(fd, "(null)", sizeof("(null)") - 1);
		return (sizeof("(null)") - 1);
	}
}
