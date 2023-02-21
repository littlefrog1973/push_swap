/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:49:13 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/20 14:31:45 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_record(char *rec, char dummy[2][500])
{
	int	len_0;
	int	len_1;

	len_0 = ft_strlen(dummy[0]);
	len_1 = ft_strlen(dummy[1]);
	if ((*dummy[0] == RA && *dummy[1] == RB) || (*dummy[0] == RRA && *dummy[1] == RRB))
	{
		if ((len_0 >= len_1))
		{
			if (dummy[0][0] == RA && dummy[1][0] == RB)
				ft_memset(&rec[ft_strlen(rec)], RR, len_1);
			if (dummy[0][0] == RRA && dummy[1][0] == RRB)
				ft_memset(&rec[ft_strlen(rec)], RRR, len_1);
			ft_memset(&rec[ft_strlen(rec)], dummy[0][0], len_0 - len_1);
		}
		else
		{
			if (dummy[0][0] == RA && dummy[1][0] == RB)
				ft_memset(&rec[ft_strlen(rec)], RR, len_0);
			if (dummy[0][0] == RRA && dummy[1][0] == RRB)
				ft_memset(&rec[ft_strlen(rec)], RRR, len_0);
			ft_memset(&rec[ft_strlen(rec)], dummy[1][0], len_1 - len_0);
		}
	return (1);
	}
	return (0);
}

int	bubble_sort_ab(t_stack *a, t_stack *b, char	*rec)
{
	char	rec_dummy[2][500];
	int		i;

	i = 1;
	while (i + 1< (*a).size)
	{
		ft_bzero(rec_dummy, 1000);
		if (is_disorder_circle(a, i + find_min(a)) == DSC)
			move_to_top_a(a, b, i + find_min(a), rec_dummy[0]);
		if (is_disorder_circle(b, i + find_max(b)) == ASC)
			move_to_top_b(a, b, i + find_max(b), rec_dummy[1]);
		if (double_record(rec, rec_dummy))
		{
			ss(a, b, rec);
			i++;
			continue;
		}
		if (is_disorder_circle(a, i + find_min(a)) == DSC)
		{
			ft_memset(&rec[ft_strlen(rec)], *rec_dummy[0], ft_strlen(rec_dummy[0]));
			sa(a, b, rec);
		}
		if (is_disorder_circle(b, i + find_max(b)) == ASC)
		{
			ft_memset(&rec[ft_strlen(rec)], *rec_dummy[1], ft_strlen(rec_dummy[1]));
			sb(a, b, rec);
		}
		i++;
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
//		bubble_sort_a(a, b, rec, ASC);
//		bubble_sort_b(a, b, rec, DSC);
		push_back_in_order(a, b, rec);
	}
	return (1);
}
