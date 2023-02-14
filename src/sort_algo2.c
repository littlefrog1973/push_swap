/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:49:15 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/14 15:47:38 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_to_top(t_stack *a, int i, char *rec)
{
	if ((i % (*a).size) < ((*a).size / 2))
	{
		while ((i % (*a).size))
		{
			ra(a, rec);
			i--;
		}
	}
	else
	{
		while ((i % (*a).size))
		{
			rra(a, rec);
			i++;
		}
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
	int	k;
	int	descen;
	int	ascend;

	j = 0;
	descen = 0;
	ascend = 0;
	while (j + 1 < (*a).size)
	{
		i = j + find_min(a);
		if ((*a).stack[i % (*a).size] < (*a).stack[(i + 1) % (*a).size])
			ascend++;
		k = j + find_max(a);
		if ((*a).stack[k % (*a).size] > (*a).stack[(k + 1) % (*a).size])
			descen++;
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

/*
int	main(void)
{
	t_stack a;
	int		a_array[] = {3, 1, 2};

	a.stack = a_array;
	a.size = 3;
	printf("is_sort_circle = %d\n", is_sort_circle(&a));
	return (0);
}
*/
