/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:06:19 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/07 14:47:34 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(char **argv)
/* Find that Is there any duplicate parameters*/
{
	int	i;
	int	duplicate;
	int	j;

	i = 1;
	while (argv[i])
		i++;
	i--;
	duplicate = 1;
	while (i >= 2)
	{
		j = i - 1;
		while (j >= 1)
		{
			if ((ft_atoi(argv[i])) == ft_atoi(argv[j]))
				return (duplicate);
			j--;
		}
		i--;
	}
	return (!duplicate);
}

int	is_all_digit(char **a)
/* Find that all data in parameters are digits or not*/
{
	int	i;
	int	digit;
	int	j;

	i = 1;
	j = 0;
	digit = 1;
	while (a[i])
	{
		j = n_pls(a[i]) + n_mns(a[i]) + n_spc(a[i]);
		while (a[i][j])
		{
			if (!ft_isdigit(a[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (digit);
}

int	is_sort_char(char **argv)
/* Find that all data in parameters are sorted in ascending order or not*/
{
	int	i;
	int	sort;

	i = 1;
	while (argv[i])
		i++;
	i--;
	sort = 1;
	while (i >= 2)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i - 1]) && sort)
			sort = 1;
		else
			sort = 0;
		i--;
	}
	return (sort);
}

int	is_overflow(char **a)
{
	int	i;

	i = 1;
	while (a[i])
	{
		if (ft_atoi(a[i]) == 0)
		{
			i++;
			continue ;
		}
		if (n_digit(ft_atoi(a[i])) != (ft_strlen(a[i]) - n_spc(a[i])
				- n_pls(a[i])))
			return (1);
		if (ft_strlen(a[i]) - n_spc(a[i]) - n_pls(a[i]) - n_mns(a[i]) > 10)
			return (1);
		if (ft_strlen(a[i]) - n_spc(a[i]) - n_pls(a[i]) == 10 && !n_mns(a[i])
			&& ft_strncmp(&a[i][n_spc(a[i]) + n_pls(a[i])], "INT_MAX", 10) > 0)
			return (1);
		if (ft_strlen(a[i]) - n_spc(a[i]) - n_mns(a[i]) == 10 && !n_pls(a[i])
			&& ft_strncmp(&a[i][n_spc(a[i]) + n_mns(a[i])], "INT_MIN", 10) > 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_argv(int argc, char **argv)
{
	if (argc == 2 && is_all_digit(argv) && !is_overflow(argv))
		exit(1);
	else if (argc == 2 && (!is_all_digit(argv) || is_overflow(argv)))
		err_exit(1);
	if (!is_all_digit(argv) || is_overflow(argv) || is_duplicate(argv))
		err_exit(1);
	if (is_sort_char(argv))
		return (0);
	return (1);
}
