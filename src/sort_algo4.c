/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:14:31 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/18 10:12:58 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_to_top_b(t_stack *a, t_stack *b, int i, char *rec)
{
	if ((i % (*b).size) < ((*b).size / 2))
	{
		while ((i % (*b).size))
		{
			rb(a, b, rec);
			i--;
		}
	}
	else
	{
		while ((i % (*b).size))
		{
			rrb(a, b, rec);
			i++;
		}
	}
	return (1);
}

int	swap_circle_b(t_stack *a, t_stack *b, char *rec, int direction)
/*direction = ASC for ascending, = DSC for descending*/
{
	int	j;

	j = 1;
	while (j + 1 < (*b).size)
	{
		if (direction == ASC)
		{
			if (is_disorder_circle(b, j + find_min(b)) == DSC)
			{
				move_to_top_b(a, b, j + find_min(b), rec);
				sb(a, b, rec);
			}
		}
		if (direction == DSC)
		{
			if (is_disorder_circle(b, j + find_max(b)) == ASC)
			{
				move_to_top_b(a, b, j + find_max(b), rec);
				sb(a, b, rec);
			}
		}
		j++;
	}
	return (1);
}

int	bubble_sort_b(t_stack *a, t_stack *b, char *rec, int direction)
/*direction = 1 for ascending, = -1 for descending*/
{
	int	i;

	i = 0;
	if (direction == ASC)
	{
		while ((is_sort_circle(b) != ASC) && (i < 15000))
		{
			swap_circle_b(a, b, rec, ASC);
			i++;
		}
		move_to_top_b(a, b, find_min(b), rec);
	}
	else if (direction == DSC)
	{
		while ((is_sort_circle(b) != DSC) && (i < 15000))
		{
			swap_circle_b(a, b, rec, DSC);
			i++;
		}
		move_to_top_b(a, b, find_max(b), rec);
	}
	return (1);
}
