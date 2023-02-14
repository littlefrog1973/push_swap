/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:12 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/14 08:13:08 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit(int err_no)
/*For any error exit*/
{
	if (err_no == 1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	if (err_no == 2)
	{
		write(2, "Error\n: Out of memory\n", 22);
		exit (1);
	}
}

size_t	n_digit(int number)
/* To find number of digit and minus sign from int value*/
{
	int	digit;
	int	sign;

	sign = 0;
	if (number < 0)
		sign++;
	digit = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		digit++;
		number = number / 10;
	}
	return (digit + sign);
}

int	n_spc(char *str)
/* To find number of space character in str*/
{
	int	num_space;
	int	i;

	num_space = 0;
	i = 0;
	while (!ft_isdigit(str[i]) && str[i] && str)
	{
		if (ft_isspace(str[i]))
			num_space++;
		if (str[i])
			i++;
	}
	return (num_space);
}

int	n_pls(char *str)
/* To find number of plus sign in str*/
{
	int	num_plus;
	int	i;

	num_plus = 0;
	i = 0;
	while (!ft_isdigit(str[i]) && str[i] && str)
	{
		if (str[i] == '+')
			num_plus++;
		if (str[i])
			i++;
	}
	return (num_plus);
}

int	n_mns(char *str)
/* To find number of minus sign in str*/
{
	int	num_minus;
	int	i;

	num_minus = 0;
	i = 0;
	while (!ft_isdigit(str[i]) && str[i] && str)
	{
		if (str[i] == '-')
			num_minus++;
		if (str[i])
			i++;
	}
	return (num_minus);
}
