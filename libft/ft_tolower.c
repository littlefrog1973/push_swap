/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:18:31 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/06/05 12:23:58 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{	
		c = c - ('A' - 'a');
	}
	return (c);
}
/*
#include <ctype.h>
#include <unistd.h>
int	main(void)
{
	int	c;
	int	d;

	c = 'A';
	d = 'A';
	c = tolower(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	d = ft_tolower(d);
	write(1, &d, 1);
	write(1, "\n", 1);
	return (0);
}*/
