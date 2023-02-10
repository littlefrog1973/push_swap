/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:42:43 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/10 00:53:54 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack *a, char *rec)
{
	if (is_sort(a) == -1)
	{
		sa(a, rec);
		rra(a, rec);
		return (1);
	}
	return (1);
}

int	sort_four(t_stack *a, t_stack *b, char *rec)
{
	b = b + 0;
	if (is_sort(a) == -1)
	{
		sa(a, rec);
		rra(a, rec);
		rra(a, rec);
		sa(a, rec);
	}
	return (1);
}
