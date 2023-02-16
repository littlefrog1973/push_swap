/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:42:43 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/16 12:14:42 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_descen(t_stack *a, t_stack *b, char *rec)
{
	move_to_top_a(a, b, find_max(a), rec);
	sa(a, b, rec);
	ra(a, b, rec);
	sa(a, b, rec);
	rra(a, b, rec);
	sa(a, b, rec);
	rra(a, b, rec);
	rra(a, b, rec);
	sa(a, b, rec);
}

int	sort_two(t_stack *a, t_stack *b, char *rec)
{
	if (is_sort(a) == -1)
	{
		sa(a, b, rec);
		return (1);
	}
	return (1);
}

int	sort_three(t_stack *a, t_stack *b, char *rec)
{
	(void) b;
	if (is_sort(a) == -1)
	{
		sa(a, b, rec);
		rra(a, b, rec);
		return (1);
	}
	else if (is_sort_circle(a) == 1)
	{
		if (find_min(a) == 0)
			return (1);
		else if (find_min(a) == 1)
			ra(a, b, rec);
		else if (find_min(a) == 2)
			rra(a, b, rec);
		return (1);
	}
	else if (find_min(a) == 1)
		sa(a, b, rec);
	else
	{
		sa(a, b, rec);
		ra(a, b, rec);
	}
	return (1);
}

int	sort_four(t_stack *a, t_stack *b, char *rec)
{
	if ((is_sort(a) == -1) || (is_sort_circle(a) == -1))
	{
		move_to_top_a(a, b, find_max(a), rec);
		sa(a, b, rec);
		rra(a, b, rec);
		rra(a, b, rec);
		sa(a, b, rec);
	}
	else if (is_sort_circle(a) == 1)
		move_to_top_a(a, b, find_min(a), rec);
	else if (find_min(a) == 0)
	{
		pb(a, b, rec);
		sort_three(a, b, rec);
		pa(a, b, rec);
	}
	else
	{
		move_to_top_a(a, b, find_min(a), rec);
		pb(a, b, rec);
		sort_three(a, b, rec);
		pa(a, b, rec);
	}
	return (1);
}

int	sort_five(t_stack *a, t_stack *b, char *rec)
{
	if (((is_sort(a) == -1) || (is_sort_circle(a) == -1)) && (*b).size == 0)
		sort_five_descen(a, b, rec);
	else if (is_sort_circle(a) == 1)
		move_to_top_a(a, b, find_min(a), rec);
	else if (find_min(a) == 0)
	{
		pb(a, b, rec);
		sort_four(a, b, rec);
		pa(a, b, rec);
	}
	else if (find_min(a) == 1)
	{
		ra(a, b, rec);
		pb(a, b, rec);
		sort_four(a, b, rec);
		pa(a, b, rec);
	}
	else
	{
		move_to_top_a(a, b, find_min(a), rec);
		pb(a, b, rec);
		sort_four(a, b, rec);
		pa(a, b, rec);
	}
	return (1);
}
