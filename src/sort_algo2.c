/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:49:15 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/13 08:48:57 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_to_top(t_stack *a, int i, char *rec)
/*Optimize by using rra for lower half and ra for upper half*/
{
	if(i <= (*a).size / 2)
		while ((i % (*a).size))
		{
			ra(a, rec);
			i--;
		}
	else
		while ((i % (*a).size))
		{
			rra(a, rec);
			i++;
		}
	return (1);
}

int	is_disorder_circle(t_stack *a, int i)
{
	int	size;

	size = (*a).size;
	if ((*a).stack[i % size] > (*a).stack[(i + 1) % size])
		return (1);
	else
		return (0);
}

int	is_sort_circle(t_stack *a)
{
	int	i;
	int	j;
	int	descen;
	int	ascend;
	int	min_pos;

	j = 0;
	descen = 0;
	ascend = 0;
	min_pos = find_min(a);
	while (j + 1< (*a).size)
	{
		i = j + min_pos;
		if ((*a).stack[i % (*a).size] < (*a).stack[(i + 1) % (*a).size])
			descen++;
		else
			ascend++;
		j++;
	}
	if (ascend + 1 == (*a).size)
		return (1);
	else if (descen + 1 == (*a).size)
		return (-1);
	else
		return (0);
}

int	swap_circle(t_stack *a, char *rec)
{
	int	i;
	int	j;

	j = 0;
	while (j + 1 < (*a).size)
	{
		i = j + find_min(a);
		if (is_disorder_circle(a, i))
		{
			move_to_top(a, i, rec);
			sa(a, rec);
		}
		j++;
	}
	return (1);
}
