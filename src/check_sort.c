/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:23:56 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/16 16:52:28 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checking(int argc, char *argv[], char *dummy)
{
	t_stack	stk_a;
	t_stack	stk_b;
	char	*order;
	int		(*order_ptr[12])(t_stack *, t_stack *, char *);
	char	tag[11][4];
	int		i;

	ft_memcpy(tag,
		"sa\0\0sb\0\0ss\0\0pa\0\0pb\0\0ra\0\0rb\0\0rr\0\0rra\0rrb\0rrr\0", 44);
	ft_bzero(order_ptr, 12 * sizeof(int *));
	order_ptr[0] =  &sa;
	order_ptr[1] =  &sb;
	order_ptr[2] =  &ss;
	order_ptr[3] =  &pa;
	order_ptr[4] =  &pb;
	order_ptr[5] =  &ra;
	order_ptr[6] =  &rb;
	order_ptr[7] =  &rr;
	order_ptr[8] =  &rra;
	order_ptr[9] =  &rrb;
	order_ptr[10] = &rrr;
	if (!init_stack(argc, argv, &stk_a, &stk_b))
		err_exit(2);
	else
	{
		order = "";
		while (order != NULL)
		{
			order = get_next_line(STDIN_FILENO);
			if (!order)
				break;
			if (order[ft_strlen(order) - 1] == '\n' && order[0])
				order[ft_strlen(order) - 1] = '\0';
			i = 0;
			while (i < 11)
			{
				if (!(ft_strncmp(tag[i], order, 3)))
					break;
				i++;
			}
			if (i == 11)
			{
				free(order);
				free_stack(&stk_a, &stk_b);
				err_exit(1);
			}
			order_ptr[i](&stk_a, &stk_b, dummy);
//			order_ptr[(int) (ft_strnstr((char *) tag, order, 4) - (char *) tag[0])](&stk_a, &stk_b, dummy);
			dummy[0] = 0;
			free(order);
		}
	}
//	free(order);
	if (is_sort(&stk_a) == ASC &&  stk_b.size == 0)
	{
		free_stack(&stk_a, &stk_b);
		return (ASC);
	}
	else
	{
		free_stack(&stk_a, &stk_b);
		return (0);
	}
}
