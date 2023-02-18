/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:55:42 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/18 10:46:29 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_half_in_order(t_stack *a, t_stack *b, char *rec)
{
	int	i;
	int	half_size_a;

	i = 0;
	half_size_a = (*a).size / 2;
	while (i < half_size_a)
	{
		move_to_top_a(a, b, find_min(a), rec);
		pb(a, b, rec);
		i++;
	}
	return (1);
}

int	push_half(t_stack *a, t_stack *b, char *rec)
{
	int	i;
	int	half_size_a;

	i = 0;
	half_size_a = (*a).size / 2;
	while (i < half_size_a)
	{
		pb(a, b, rec);
		i++;
	}
	return (1);
}

int	push_back(t_stack *a, t_stack *b, char *rec)
{
	int	i;
	int	size_b;

	i = 0;
	size_b = (*b).size;
	while (i < size_b)
	{
		pa(a, b, rec);
		i++;
	}
	return (1);
}

int	push_back_in_order(t_stack *a, t_stack *b, char *rec)
{
	int	i;

	i = 0;
	while (!(is_sort(a) && ((*b).size == 0)))
	{
		if (!is_sort(a) || !i)
		{
			if (((*a).stack[(*a).size - 1] < (*b).stack[0]) && (*b).size > 0)
				pa(a, b, rec);
			else
			{
				rra(a, b, rec);
			}
		}
		else if (is_sort(a) && ((*b).size > 0) && i)
			pa(a, b, rec);
		i++;
	}
	return (1);
}

int	sort_hi_n(t_stack *a, t_stack *b, char *rec)
{
	if (is_sort(a) == 1 && (*b).size == 0)
		return (1);
	else if ((is_sort_circle(a) == 1) && ((*b).size == 0))
	{
		move_to_top_a(a, b, find_min(a), rec);
	}
	else if ((*a).size > 5 && (*a).size < 13)
	{
		push_half_in_order(a, b, rec);
		bubble_sort_a(a, b, rec, ASC);
		push_back(a, b, rec);
	}
	else
	{
		push_half(a, b, rec);
		bubble_sort_a(a, b, rec, ASC);
		bubble_sort_b(a, b, rec, DSC);
		push_back_in_order(a, b, rec);
	}
	return (1);
}
