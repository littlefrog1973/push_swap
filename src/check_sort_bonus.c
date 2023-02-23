/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 08:23:56 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/17 15:00:48 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_function_ptr(int (*order_ptr[])(t_stack *a, t_stack *b, char *rec))
{
	ft_bzero(order_ptr, 12 * sizeof(int *));
	order_ptr[0] = &sa;
	order_ptr[1] = &sb;
	order_ptr[2] = &ss;
	order_ptr[3] = &pa;
	order_ptr[4] = &pb;
	order_ptr[5] = &ra;
	order_ptr[6] = &rb;
	order_ptr[7] = &rr;
	order_ptr[8] = &rra;
	order_ptr[9] = &rrb;
	order_ptr[10] = &rrr;
}

void	init_tag(char tag[][4])
{
	ft_memcpy(tag,
		"sa\0\0sb\0\0ss\0\0pa\0\0pb\0\0ra\0\0rb\0\0rr\0\0rra\0rrb\0rrr\0", 44);
}

int	search_order(char tag[][4], char *order)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!(ft_strncmp(tag[i], order, 3)))
			break ;
		i++;
	}
	return (i);
}

int	checking(t_stack *a, t_stack *b, char *dummy, char *order)
{
	int		(*order_ptr[12])(t_stack *, t_stack *, char *);
	char	tag[11][4];
	int		i;

	init_tag(tag);
	init_function_ptr(order_ptr);
	while (order != NULL)
	{
		order = get_next_line(STDIN_FILENO);
		if (!order)
			break ;
		if (order[ft_strlen(order) - 1] == '\n' && order[0])
			order[ft_strlen(order) - 1] = '\0';
		i = search_order(tag, order);
		if (i >= 11)
			err_exit_free_mem(order, a, b, 1);
		order_ptr[i](a, b, dummy);
		dummy[0] = 0;
		free(order);
	}
	if (is_sort(a) == ASC && (*b).size == 0)
		return (ASC);
	else
		return (0);
}
