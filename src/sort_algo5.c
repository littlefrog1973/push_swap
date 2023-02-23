/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:49:13 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/23 10:01:04 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_n(t_stack *a, int to_find)
{
	int	i;

	i = 0;
	while (i < (*a).size)
	{
		if ((*a).stack[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	double_record(char *rec, char dmy[2][500])
{
	if ((*dmy[0] == RA && *dmy[1] == RB) || (*dmy[0] == RRA && *dmy[1] == RRB))
	{
		if ((ft_strlen(dmy[0]) >= ft_strlen(dmy[1])))
		{
			if (dmy[0][0] == RA && dmy[1][0] == RB)
				ft_memset(&rec[ft_strlen(rec)], RR, ft_strlen(dmy[1]));
			if (dmy[0][0] == RRA && dmy[1][0] == RRB)
				ft_memset(&rec[ft_strlen(rec)], RRR, ft_strlen(dmy[1]));
			ft_memset(&rec[ft_strlen(rec)], dmy[0][0], ft_strlen(dmy[0])
				- ft_strlen(dmy[1]));
		}
		else
		{
			if (dmy[0][0] == RA && dmy[1][0] == RB)
				ft_memset(&rec[ft_strlen(rec)], RR, ft_strlen(dmy[0]));
			if (dmy[0][0] == RRA && dmy[1][0] == RRB)
				ft_memset(&rec[ft_strlen(rec)], RRR, ft_strlen(dmy[0]));
			ft_memset(&rec[ft_strlen(rec)], dmy[1][0], ft_strlen(dmy[1])
				- ft_strlen(dmy[0]));
		}
		return (1);
	}
	return (0);
}

int	bubble_sort_ab(t_stack *a, t_stack *b, char	*rec)
{
	char	rec_dmy[2][500];
	int		i;

	i = 1;
	while (i++ < (*a).size - 1)
	{
		ft_bzero(rec_dmy, 1000);
		if (is_disorder_circle(a, i + find_min(a)) == DSC)
			move_to_top_a(a, b, i + find_min(a), rec_dmy[0]);
		if (is_disorder_circle(b, i + find_max(b)) == ASC)
			move_to_top_b(a, b, i + find_max(b), rec_dmy[1]);
		if (double_record(rec, rec_dmy))
		{
			ss(a, b, rec);
			continue ;
		}
		ft_memset(&rec[ft_strlen(rec)], *rec_dmy[0], ft_strlen(rec_dmy[0]));
		ft_memset(&rec[ft_strlen(rec)], *rec_dmy[1], ft_strlen(rec_dmy[1]));
		if (is_disorder_circle(a, i + find_min(a)) == DSC)
			sa(a, b, rec);
		if (is_disorder_circle(b, i + find_max(b)) == ASC)
			sb(a, b, rec);
	}
	return (1);
}

int	sort_hi_n_ab(t_stack *a, t_stack *b, char *rec)
{
	if (is_sort(a) == 1 && (*b).size == 0)
		return (1);
	else if ((is_sort_circle(a) == ASC) && ((*b).size == 0))
		move_to_top_a(a, b, find_min(a), rec);
	else if ((*a).size > 5 && (*a).size < 8)
	{
		push_half_in_order(a, b, rec);
		bubble_sort_a(a, b, rec, ASC);
		push_back(a, b, rec);
	}
	else
	{
		push_half(a, b, rec);
		while (is_sort_circle(a) != ASC || is_sort_circle(b) != DSC)
			bubble_sort_ab(a, b, rec);
		move_to_top_a(a, b, find_min(a), rec);
		move_to_top_b(a, b, find_max(b), rec);
		push_back_in_order(a, b, rec);
	}
	return (1);
}
