/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:08 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/23 09:26:34 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	log_base2(int n)
{
	int	dummy;
	int	i;

	i = 0;
	dummy = 1;
	if (n == 1)
		return (0);
	while (dummy < n)
	{
		dummy = dummy << 1;
		i++;
	}
	return (i);
}

int	sum_stack(t_stack *a)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < (*a).size)
	{
		sum = sum + (*a).stack[i];
		i++;
	}
	return (sum);
}

void	bubble_sort(t_stack *a, int direction)
{
	int	i;
	int	j;
	int	dummy;

	i = 0;
	while (i + 1 < (*a).size)
	{
		j = i + 1;
		while (j < (*a).size)
		{
			if (direction == ASC)
			{
				if ((*a).stack[i] > (*a).stack[j])
				{
					dummy = (*a).stack[i];
					(*a).stack[i] = (*a).stack[j];
					(*a).stack[j] = dummy;
				}
			}
			j++;
		}
		i++;
	}
}

void	normalized(t_stack *a, t_stack *b)
{
	int	i;

	ft_memcpy((*b).stack, (*a).stack, (*a).size * sizeof((*b).stack[0]));
	(*b).size = (*a).size;
	bubble_sort(b, ASC);
	i = 0;
	while (i < (*a).size)
	{
		(*a).stack[i] = find_n(b, (*a).stack[i]);
		i++;
	}
	ft_memset((*b).stack, 0, (*b).size * sizeof((*b).stack[0]));
	(*b).size = 0;
}
/*
int	find_mid(t_stack *a)
{
	int	i;
	int	dummy;
	int	pos;
	int	avg;

	i = 0;
	dummy = 0;
	pos = 0;
	avg = sum_stack(a) / (*a).size;
	while (i < (*a).size)
	{
		if ((*a).stack[i] < avg)
			dummy = avg - (*a).stack[i];
		else
			dummy = (*a).stack[i] - avg;
		i++;
	}
	return (pos);
}
*/
