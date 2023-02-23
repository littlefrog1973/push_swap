/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:50:45 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/23 06:42:21 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_to_stack(t_stack *a, t_stack *b, char *rec, int digit)
{
	int	a_size;

	a_size = (*a).size;
	while (a_size--)
	{
		if ((((*a).stack[0] >> digit) & 1) == 1)
			ra(a, b, rec);
		else
			pb(a, b, rec);
	}
}

void	reunite(t_stack *a, t_stack *b, char *rec)
{
	while ((*b).size > 0)
		pa(a, b, rec);
}

int	find_max_digit(t_stack *a)
{
	int	max;
	int	digit;

	max = (*a).stack[find_max(a)];
	digit = 0;
	while (max >> digit)
		digit++;
	return (digit);
}

void	sort_hi_radix(t_stack *a, t_stack *b, char *rec)
{
	int	max_digit;
	int	i;

	if (is_sort(a) == 1 && (*b).size == 0)
		return ;
	else if ((is_sort_circle(a) == ASC) && ((*b).size == 0))
		move_to_top_a(a, b, find_min(a), rec);
	else if ((*a).size > 5 && (*a).size < 27)
	{
		push_half_in_order(a, b, rec);
		bubble_sort_a(a, b, rec, ASC);
		push_back(a, b, rec);
	}
	else
	{
		normalized(a, b);
		max_digit = find_max_digit(a);
		i = 0;
		while (max_digit--)
		{
			divide_to_stack(a, b, rec, i);
			reunite(a, b, rec);
			i++;
		}
	}
}
