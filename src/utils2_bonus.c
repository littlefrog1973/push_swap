/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:19:15 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/23 10:22:47 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit_free_mem(char *order, t_stack *a, t_stack *b, int err_no)
{
	if (err_no == 1)
	{
		free(order);
		free_stack(a, b);
		err_exit(1);
	}
}

int	n_spc_back(char *str)
/* To find number of space character in str*/
{
	int	num_space;
	int	i;

	num_space = 0;
	i = n_pls(str) + n_mns(str) + n_spc(str);
	while (ft_isdigit(str[i]) && str[i] && str)
			i++;
	while (ft_isspace(str[i]) && str[i] && str)
	{
		num_space++;
		i++;
	}
	return (num_space);
}

int	move_to_bottom_a(t_stack *a, t_stack *b, int i, char *rec)
{
	if ((i % (*a).size) < ((*a).size / 2))
	{
		while (((i + (*a).size) % (*a).size) != (*a).size - 1)
		{
			ra(a, b, rec);
			i--;
		}
	}
	else
	{
		while ((i % (*a).size) != (*a).size - 1)
		{
			rra(a, b, rec);
			i++;
		}
	}
	return (1);
}

int	is_sort(t_stack *a)
/*return = 0 not sort, = ASC ascending sort, = DSC descending sort*/
{
	int	i;
	int	ascend;
	int	descen;

	i = 0;
	ascend = 0;
	descen = 0;
	while (i + 1 < (*a).size)
	{
		if ((*a).stack[i] < (*a).stack[i + 1])
			ascend++;
		else
			descen++;
		i++;
	}
	if (ascend + 1 == (*a).size)
		return (ASC);
	else if (descen + 1 == (*a).size)
		return (DSC);
	else
		return (0);
}
