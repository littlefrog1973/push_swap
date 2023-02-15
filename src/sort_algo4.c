/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:14:31 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/15 13:31:53 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_to_top_b(t_stack *a, int i, char *rec)
{
	if ((i % (*a).size) < ((*a).size / 2))
	{
		while ((i % (*a).size))
		{
			rb(a, rec);
			i--;
		}
	}
	else
	{
		while ((i % (*a).size))
		{
			rrb(a, rec);
			i++;
		}
	}
	return (1);
}

int	swap_circle_b(t_stack *a, char *rec, int direction)
/*direction = ASC for ascending, = DSC for descending*/
{
	int	i;
	int	j;

	j = 1;
	if (direction == ASC)
	{
		while (j + 1 < (*a).size)
		{
			i = j + find_min(a);
			if (is_disorder_circle(a, i) == DSC)
			{
				move_to_top_b(a, i, rec);
				sb(a, rec);
			}
			j++;
		}
	}
	if (direction == DSC)
	{
		while (j + 1 < (*a).size)
		{
			i = j + find_max(a);
			if (is_disorder_circle(a, i) == ASC)
			{
				move_to_top_b(a, i, rec);
				sb(a, rec);
			}
			j++;
		}
	}
	return (1);
}

int	bubble_sort_b(t_stack *a, char *rec, int direction)
/*direction = 1 for ascending, = -1 for descending*/
{
	int	i;

	i = 0;
	if (direction == ASC)
	{
		while ((is_sort_circle(a) != ASC) && (i < 15000))
		{
			swap_circle_b(a, rec, ASC);
			i++;
		}
		move_to_top_b(a, find_min(a), rec);
	}
	else if (direction == DSC)
	{
		while ((is_sort_circle(a) != DSC) && (i < 15000))
		{
			swap_circle_b(a, rec, DSC);
			i++;
		}
		move_to_top_b(a, find_max(a), rec);
	}
	return (1);
}
