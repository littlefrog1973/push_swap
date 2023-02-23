/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:31:36 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/23 09:36:09 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort_circle_chunk(t_stack *a, int stt, int chunk_size)
{
	int	descen;
	int	ascend;
	int	start;

	descen = 0;
	ascend = 0;
	start = stt;
	while ((stt % (*a).size) != start + chunk_size - 1)
	{
		if ((*a).stack[stt % (*a).size] < (*a).stack[(stt + 1) % (*a).size])
			ascend++;
		if ((*a).stack[stt % (*a).size] > (*a).stack[(stt + 1) % (*a).size])
			descen++;
		stt++;
	}
	if (ascend + 1 == chunk_size)
		return (ASC);
	else if (descen + 1 == chunk_size)
		return (DSC);
	else
		return (0);
}

void	chunk_size(int a_size, int *chunk_no)
{
	int	i;

	i = 0;
	while (i + 1 < CHUNK_SIZE)
	{
		chunk_no[i] = a_size / CHUNK_SIZE;
		i++;
	}
	chunk_no[CHUNK_SIZE - 1] = a_size - ((CHUNK_SIZE - 1) * chunk_no[0]);
}

int	bubble_sort_chunk(t_stack *a, t_stack *b, char *rec, int *chunk_no)
/*direction = 1 for ascending, = -1 for descending*/
{
	static int	i;

	(void) b;
	(void) rec;
	if (i == CHUNK_SIZE)
		i = 0;
	while ((is_sort_circle_chunk(a, i * chunk_no[0], chunk_no[i]) != ASC))
	{
		i++;
	}
	i++;
	return (1);
}

void	find_chunk_pos(t_stack *a, int *chunk_no, int *chunk_pos)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	ft_bzero(chunk_pos, CHUNK_SIZE * sizeof(chunk_pos[0]));
	while (i < (*a).size)
	{
		j = 0;
		while (j < CHUNK_SIZE)
		{
			start = j * chunk_no[0];
			if ((*a).stack[i] >= start && (*a).stack[i] < start + chunk_no[i])
			{
				chunk_pos[j]++;
			}
			j++;
		}
		i++;
	}
}

int	sort_hi_chunk(t_stack *a, t_stack *b, char *rec)
{
	int	chunk_no[CHUNK_SIZE];

	(void) rec;
	normalized(a, b);
	chunk_size((*a).size, chunk_no);
	sort_chunk(chunk_no, a, b, rec);
	return (1);
}
