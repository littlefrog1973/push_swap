/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:31:36 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/21 17:17:14 by sdeeyien         ###   ########.fr       */
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

int	move_to_bottom_a(t_stack *a, t_stack *b, int i, char *rec)
{
	if ((i % (*a).size) < ((*a).size / 2))
	{
		while (((i + (*a).size) % (*a).size) != (*a).size - 1)
		{
			ra(a, b, rec);
			i--;
		}
	}
	else
	{
		while ((i % (*a).size) != (*a).size - 1)
		{
			rra(a, b, rec);
			i++;
		}
	}
	return (1);
}

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

void	bubble_sort(t_stack *a, int	direction)
{
	int	i;
	int	j;
	int	dummy;
/*	Try bubble sort first*/

	i = 0;
	while (i + 1< (*a).size)
	{
		j = i + 1;
		while (j < (*a).size)
		{
			if (direction == ASC)
			{
				if ((*a).stack[i] > (*a).stack[j])
				{
					dummy = (*a).stack[i];
					(*a).stack[i] = (*a).stack[j];
					(*a).stack[j] = dummy;
				}
			}
			j++;
		}
		i++;
	}
}

void	normalized(t_stack *a, t_stack *b)
{
	int	i;

	ft_memcpy((*b).stack, (*a).stack, (*a).size * sizeof((*b).stack[0]));
	(*b).size = (*a).size;
	bubble_sort(b, ASC);
	i = 0;
	while (i < (*a).size)
	{
		(*a).stack[i] = find_n(b, (*a).stack[i]);
		i++;
	}
	ft_memset((*b).stack, 0, (*b).size * sizeof((*b).stack[0]));
	(*b).size = 0;
}

void	chunk_size(int	a_size, int	*chunk_no)
{
	int	i;

	i = 0;
	while ( i + 1 < CHUNK_SIZE)
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

void	put_chunk(t_stack *a, t_stack *b, char *rec, int *chunk_no)
{
	int	chunk_pos[CHUNK_SIZE];

	(void) b;
	(void) rec;
	find_chunk_pos(a, chunk_no, chunk_pos);
/*
	int start;
	int	i;
	int	start_i;
	int	j;

	i = 0;
	while (i < CHUNK_SIZE)
	{
		start = i * chunk_no[0];
		start_i = find_n(a, start);
		j = 1;
		while (j < chunk_no[i])
		{
			if ((*a).stack[(start_i + j) % (*a).size] < start)
			{
				move_to_top_a(a, b, start_i + j, rec);
				pb(a, b, rec);
				move_to_top_a(a, b, start_i, rec);
				pa(a, b, rec);
			}
			else if((*a).stack[(start_i + j) % (*a).size] >= start + chunk_no[i])
			{
				move_to_top_a(a, b, start_i + j, rec);
				sa(a, b, rec);
			}
			j++;
		}
		i++;
	}
*/
}
int	sort_chunk(int	*chunk_no, t_stack *a, t_stack *b, char *rec)
{
//	int	i;

	put_chunk(a, b, rec, chunk_no);
	return (1);
}

int	sort_hi_chunk(t_stack *a, t_stack *b, char *rec)
{
//	int	i;
	int	chunk_no[CHUNK_SIZE];

	(void) rec;
	normalized(a, b);
	chunk_size((*a).size, chunk_no);
	sort_chunk(chunk_no, a, b, rec);
	return (1);
}
