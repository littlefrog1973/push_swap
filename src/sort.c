/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:14:40 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/23 10:27:05 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_low_n(t_stack *a, t_stack *b, char *rec)
{
	if (is_sort(a) == 1 && (*b).size == 0)
		return (1);
	else
	{
		if ((*a).size == 2)
			sort_two(a, b, rec);
		if ((*a).size == 3)
			sort_three(a, b, rec);
		if ((*a).size == 4)
			sort_four(a, b, rec);
		if ((*a).size == 5)
			sort_five(a, b, rec);
		else
			return (0);
		return (1);
	}
}

int	bubble_sort_a(t_stack *a, t_stack *b, char *rec, int direction)
/*direction = 1 for ascending, = -1 for descending*/
{
	int	i;

	i = 0;
	if (direction == ASC)
	{
		while ((is_sort_circle(a) != ASC) && (i < 15000))
		{
			swap_circle_a(a, b, rec, ASC);
			i++;
		}
		move_to_top_a(a, b, find_min(a), rec);
	}
	else if (direction == DSC)
	{
		while ((is_sort_circle(a) != DSC) && (i < 15000))
		{
			swap_circle_a(a, b, rec, DSC);
			i++;
		}
		move_to_top_a(a, b, find_max(a), rec);
	}
	return (1);
}
/*
int	bubble_sort(t_stack *a, t_stack *b, char *rec)
{
	int	i;

	if (is_sort(a) == 1 && (*b).size == 0)
		return (1);
	else
	{
		i = 0;
		while (!(is_sort_circle(a) == 1 && (*b).size == 0) && i < 15000)
		{
			swap_circle(a, rec);
			i++;
		}
	}
	move_to_top(a, find_min(a), rec);
	return (1);
}
*/

char	*sorting(int argc, char **argv)
{
	t_stack	stk_a;
	t_stack	stk_b;
	char	*rec;

	rec = NULL;
	if (init_stack(argc, argv, &stk_a, &stk_b))
		rec = init_record(argc - 1);
	if (!rec)
		free_stack(&stk_a, &stk_b);
	if (argc <= 6)
		sort_low_n(&stk_a, &stk_b, rec);
	else
		sort_hi_radix(&stk_a, &stk_b, rec);
	free_stack(&stk_a, &stk_b);
	return (rec);
}
