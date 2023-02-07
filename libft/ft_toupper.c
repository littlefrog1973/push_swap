/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:44 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/06/05 12:00:23 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{	
		c = c + ('A' - 'a');
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

//	c = '\129';
//	d = '\129';
	c = toupper(128);
	write(1, &c, 1);
	write(1, "\n", 1);
	d = ft_toupper(128);
	write(1, &d, 1);
	write(1, "\n", 1);
	return (0);
}*/
