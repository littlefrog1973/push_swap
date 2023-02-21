/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:31:36 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/20 17:23:40 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_n(t_stack *a, int to_find)
{
	int	i;

	i = 0;
	while (i < (*a).size)
	{
		if ((*a).stack[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

void	merge_sort(t_stack *a, int	direction)
{
	int	i;
	int	j;
	int	dummy;
/*	Try bubble sort first*/

	i = 0;
	while (i + 1< (*a).size)
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

int	sort_hi_chunk(t_stack *a, t_stack *b, char *rec)
{
	int	i;

	(void) rec;
	ft_memcpy((*b).stack, (*a).stack, (*a).size * sizeof(int));
	(*b).size = (*a).size;
	merge_sort(b, ASC);
	i = 0;
	while (i < (*a).size)
	{
		(*a).stack[i] = find_n(b, (*a).stack[i]);
		i++;
	}
	ft_memset((*b).stack, 0, (*b).size * sizeof(int));
	(*b).size = 0;
	return (1);
}
