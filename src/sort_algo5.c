/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:49:13 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/18 23:51:43 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_record(char *rec, char rec_dummy[2][500])
{
	int	i;

	i = 0;
	if (ft_strlen(rec_dummy[0]) > ft_strlen(rec_dummy[1]))

}

int	bubble_sort_ab(t_stack *a, t_stack *b, char	*rec)
{
	char	rec_dummy[2][500];
	int		i;

	i = 1;
	push_half(a, b, rec);
	while (i < (*a).size)
	{
		ft_bzero(rec_dummy, 1000);
		if (is_disorder_circle(a, i + find_min(a)) == DSC)
		{
			move_to_top_a(a, b, i + find_min(a), rec_dummy[0]);
		}
		if (is_disorder_circle(b, i + find_max(b)) == ASC)
		{
			move_to_top_b(a, b, i + find_max(b), rec_dummy[1]);
		}
		if (double_record(rec, rec_dummy))
			ss(a, b, rec);
		else if (rec_dummy[0])
			sa(a, b, rec);
		else if (rec_dummy[1])
			sb(a, b, rec);
		i++;
	}
}
