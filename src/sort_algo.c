/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:42:43 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/14 15:48:14 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_descen(t_stack *a, char *rec)
{
	move_to_top(a, find_max(a), rec);
	sa(a, rec);
	ra(a, rec);
	sa(a, rec);
	rra(a, rec);
	sa(a, rec);
	rra(a, rec);
	rra(a, rec);
	sa(a, rec);
}

int	sort_two(t_stack *a, char *rec)
{
	if (is_sort(a) == -1)
	{
		sa(a, rec);
		return (1);
	}
	return (1);
}

int	sort_three(t_stack *a, char *rec)
{
	if (is_sort(a) == -1)
	{
		sa(a, rec);
		rra(a, rec);
		return (1);
	}
	else if (is_sort_circle(a) == 1)
	{
		if (find_min(a) == 0)
			return (1);
		else if (find_min(a) == 1)
			ra(a, rec);
		else if (find_min(a) == 2)
			rra(a, rec);
		return (1);
	}
	else if (find_min(a) == 1)
		sa(a, rec);
	else
	{
		sa(a, rec);
		ra(a, rec);
	}
	return (1);
}

int	sort_four(t_stack *a, t_stack *b, char *rec)
{
	if ((is_sort(a) == -1) || (is_sort_circle(a) == -1))
	{
		move_to_top(a, find_max(a), rec);
		sa(a, rec);
		rra(a, rec);
		rra(a, rec);
		sa(a, rec);
	}
	else if (is_sort_circle(a) == 1)
		move_to_top(a, find_min(a), rec);
	else if (find_min(a) == 0)
	{
		pb(a, b, rec);
		sort_three(a, rec);
		pa(a, b, rec);
	}
	else
	{
		move_to_top(a, find_min(a), rec);
		pb(a, b, rec);
		sort_three(a, rec);
		pa(a, b, rec);
	}
	return (1);
}

int	sort_five(t_stack *a, t_stack *b, char *rec)
{
	if (((is_sort(a) == -1) || (is_sort_circle(a) == -1)) && (*b).size == 0)
		sort_five_descen(a, rec);
	else if (is_sort_circle(a) == 1)
		move_to_top(a, find_min(a), rec);
	else if (find_min(a) == 0)
	{
		pb(a, b, rec);
		sort_four(a, b, rec);
		pa(a, b, rec);
	}
	else if (find_min(a) == 1)
	{
		ra(a, rec);
		pb(a, b, rec);
		sort_four(a, b, rec);
		pa(a, b, rec);
	}
	else
	{
		move_to_top(a, find_min(a), rec);
		pb(a, b, rec);
		sort_four(a, b, rec);
		pa(a, b, rec);
	}
	return (1);
}
