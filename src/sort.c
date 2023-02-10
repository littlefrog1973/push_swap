/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:14:40 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/10 01:07:36 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_stack *a)
/*return = 0 not sort, = 1 ascending sort, = -1 descending sort*/
{
	int	i;
	int	ascend;
	int	descen;

	i = 0;
	ascend = 0;
	descen = 0;
	while (i + 1 < (*a).size)
	{
		if ((*a).stack[i] < (*a).stack[i + 1])
			ascend++;
		else
			descen++;
		i++;
	}
	if (ascend + 1 == (*a).size)
		return (1);
	else if (descen + 1 == (*a).size)
		return (-1);
	else
		return (0);
}

int	sort_low_n(t_stack *a, t_stack *b, char *rec)
{
	if (is_sort(a) == 1 && (*b).size == 0)
		return (1);
	else
	{
		if ((*a).size == 3)
			sort_three(a, rec);
		else if ((*a).size == 4)
			sort_four(a, b, rec);
		else
			return (0);
		return (1);
	}
}

int	sort_hi_n(t_stack *a, t_stack *b, char *rec)
{
	rec = rec + 0;
	if (is_sort(a) == 1 && (*b).size == 0)
		return (1);
	return (1);
}

char	*sorting(int argc, char **argv)
{
	t_stack	stk_a;
	t_stack	stk_b;
	char	*rec;

	if (is_sort_char(argv))
		return ("");
	else
	{
		if (argc == 3)
		{
			ft_printf("sa\n");
			return ("");
		}
		if (init_stack(argc, argv, &stk_a, &stk_b))
			rec = init_record(argc - 1);
		if (!rec)
			free_stack(&stk_a, &stk_b);
		if (argc < 5)
			sort_low_n(&stk_a, &stk_b, rec);
		else
			sort_hi_n(&stk_a, &stk_b, rec);
	}
	free_stack(&stk_a, &stk_b);
	return (rec);
}

/*
	i = 0;
	while (i <stk_a.size)
	{
		ft_printf("stk_a[%d] = %d\n", i, stk_a.stack[i]);
		i++;
	}
	i = 0;
	while (i <stk_b.size)
	{
		ft_printf("stk_b[%d] = %d\n", i, stk_b.stack[i]);
		i++;
	}
*/
