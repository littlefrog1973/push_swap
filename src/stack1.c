/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:38:54 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/08 16:30:19 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *a, char *rec)
{
	int	dummy;
	int	i;

	i = 0;
	while (rec[i])
		i++;
	rec[i] = SA;
	if ((*a).size == 1)
		return (0);
	else
	{
		dummy = (*a).stack[0];
		(*a).stack[0] = (*a).stack[1];
		(*a).stack[1] = dummy;
		return (1);
	}
}

int	sb(t_stack *b, char *rec)
{
	int	dummy;
	int	i;

	i = 0;
	while (rec[i])
		i++;
	rec[i] = SB;
	if ((*b).size == 1)
		return (0);
	else
	{
		dummy = (*b).stack[0];
		(*b).stack[0] = (*b).stack[1];
		(*b).stack[1] = dummy;
		return (1);
	}
}
int	ss(t_stack *a, t_stack *b, char *rec)
{
	int	dummy;
	int	i;

	i = 0;
	while (rec[i])
		i++;
	rec[i] = SS;
	if ((*a).size > 1)
	{
		dummy = (*a).stack[0];
		(*a).stack[0] = (*a).stack[1];
		(*a).stack[1] = dummy;
	}
	if ((*b).size > 1)
	{
		dummy = (*b).stack[0];
		(*b).stack[0] = (*b).stack[1];
		(*b).stack[1] = dummy;
	}
	if ((*a).size == 1 && (*b).size == 1)
		return (0);
	else
		return (1);
}

int	pa(t_stack *a, t_stack *b, char *rec)
{
	int	i;

	i = (int) ft_strlen(rec);
	rec[i] = PA;
	if ((*b).size == 0)
		return (0);
	else
	{
		i = (*a).size++;
		while (i > 0)
		{
			(*a).stack[i] = (*a).stack[i - 1];
			i--;
		}
		(*a).stack[i] = (*b).stack[0];
		while (i < (*b).size)
		{
				(*b).stack[i] = (*b).stack[i + 1];
			i++;
		}
		(*b).size--;
	}
	return (1);
}

int	pb(t_stack *b, t_stack *a, char *rec)
{
	int	i;

	i = (int) ft_strlen(rec);
	rec[i] = PB;
	if ((*b).size == 0)
		return (0);
	else
	{
		i = (*a).size++;
		while (i > 0)
		{
			(*a).stack[i] = (*a).stack[i - 1];
			i--;
		}
		(*a).stack[i] = (*b).stack[0];
		while (i < (*b).size)
		{
				(*b).stack[i] = (*b).stack[i + 1];
			i++;
		}
		(*b).size--;
	}
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

	pb(&a, &b, cc);
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
	return (0);
}
*/
