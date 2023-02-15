/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:08 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/15 11:07:40 by sdeeyien         ###   ########.fr       */
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
