/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:19:15 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/17 10:23:47 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void err_exit_free_mem(char *order, t_stack *a, t_stack *b, int err_no)
{
	if (err_no == 1)
	{
		free(order);
		free_stack(a, b);
		err_exit(1);
	}
}
