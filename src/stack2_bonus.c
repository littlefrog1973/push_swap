/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:31:37 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/21 08:43:58 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *a, t_stack *b, char *rec)
{
	int	dummy;
	int	i;

	(void) b;
	i = (int) ft_strlen(rec);
	rec[i] = RA;
	if ((*a).size <= 1)
		return (0);
	else
	{
		i = 0;
		dummy = (*a).stack[0];
		while (i + 1 < (*a).size)
		{
			(*a).stack[i] = (*a).stack[i + 1];
			i++;
		}
		(*a).stack[i] = dummy;
		return (1);
	}
}

int	rb(t_stack *a, t_stack *b, char *rec)
{
	int	dummy;
	int	i;

	(void) a;
	i = (int) ft_strlen(rec);
	rec[i] = RB;
	if ((*b).size <= 1)
		return (0);
	else
	{
		i = 0;
		dummy = (*b).stack[0];
		while (i + 1 < (*b).size)
		{
			(*b).stack[i] = (*b).stack[i + 1];
			i++;
		}
		(*b).stack[i] = dummy;
		return (1);
	}
}

int	rr(t_stack *a, t_stack *b, char *rec)
{
	char	rec_dummy[2];
	int		i;

	ft_bzero(rec_dummy, 2);
	i = (int) ft_strlen(rec);
	rec[i] = RR;
	if ((*a).size <= 1 && (*b).size <= 1)
		return (0);
	if ((*a).size > 1)
		ra(a, b, rec_dummy);
	if ((*b).size > 1)
		rb(a, b, rec_dummy);
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

//	ra(&a, cc);
//	rb(&b, cc);
	rr(&a, &b, cc);
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
