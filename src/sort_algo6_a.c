/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo6_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:34:40 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/23 10:00:08 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_chunk(t_stack *a, t_stack *b, char *rec, int *chunk_no)
{
	int	chunk_pos[CHUNK_SIZE];

	(void) b;
	(void) rec;
	find_chunk_pos(a, chunk_no, chunk_pos);
}

int	sort_chunk(int	*chunk_no, t_stack *a, t_stack *b, char *rec)
{
	put_chunk(a, b, rec, chunk_no);
	return (1);
}
