/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:30:14 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/17 16:32:10 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *a, t_stack *b, char *rec)
{
	int	dummy;
	int	i;

	dummy = (*b).size;
	i = (int) ft_strlen(rec);
	rec[i] = RRA;
	if ((*a).size == 1)
		return (0);
	else
	{
		i = (*a).size - 1;
		dummy = (*a).stack[i];
		while (i > 0)
		{
			(*a).stack[i] = (*a).stack[i - 1];
			i--;
		}
		(*a).stack[i] = dummy;
		return (1);
	}
}

int	rrb(t_stack *a, t_stack *b, char *rec)
{
	int	dummy;
	int	i;

	dummy = (*a).size;
	i = (int) ft_strlen(rec);
	rec[i] = RRB;
	if ((*b).size == 1)
		return (0);
	else
	{
		i = (*b).size - 1;
		dummy = (*b).stack[i];
		while (i > 0)
		{
			(*b).stack[i] = (*b).stack[i - 1];
			i--;
		}
		(*b).stack[i] = dummy;
		return (1);
	}
}

int	rrr(t_stack *a, t_stack *b, char *rec)
{
	char	rec_dummy[2];
	int		i;

	ft_bzero(rec_dummy, 2);
	i = (int) ft_strlen(rec);
	rec[i] = RRR;
	if ((*a).size > 1)
		rra(a, b, rec_dummy);
	if ((*b).size > 1)
		rrb(b, a, rec_dummy);
	if ((*a).size == 1 && (*b).size == 1)
		return (0);
	return (1);
}
/*
int	main(void)
{
	int		aa[] = {1, 2, 3, 0};
	int		bb[] = {4, 5, 0, 0};
	t_stack	a;
	t_stack b;
	char	cc[5] = {'a', 'b', 0, 0, 0};

	a.stack = aa;
	a.size = 3;
	b.stack = bb;
	b.size = 2;

	rra(&a, &b, cc);
	rrb(&a, &b, cc);
	rrr(&a, &b, cc);
	printf("aa[0] = %d\n", a.stack[0]);
	printf("aa[1] = %d\n", a.stack[1]);
	printf("aa[2] = %d\n", a.stack[2]);
	printf("aa[3] = %d\n", a.stack[3]);
	printf("a.size = %d\n", a.size);
	printf("bb[0] = %d\n", b.stack[0]);
	printf("bb[1] = %d\n", b.stack[1]);
	printf("bb[2] = %d\n", b.stack[2]);
	printf("bb[3] = %d\n", b.stack[3]);
	printf("b.size = %d\n", b.size);
	printf("cc[0] = %c\n", cc[0]);
	printf("cc[1] = %c\n", cc[1]);
	printf("cc[2] = %c\n", cc[2]);
	printf("cc[3] = %c\n", cc[3]);
	return (0);
}
*/
