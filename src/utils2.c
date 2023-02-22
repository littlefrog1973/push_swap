/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:19:15 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/22 12:08:40 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_exit_free_mem(char *order, t_stack *a, t_stack *b, int err_no)
{
	if (err_no == 1)
	{
		free(order);
		free_stack(a, b);
		err_exit(1);
	}
}

int	n_spc_back(char *str)
/* To find number of space character in str*/
{
	int	num_space;
	int	i;

	num_space = 0;
	i = n_pls(str) + n_mns(str) + n_spc(str);
	while (ft_isdigit(str[i]) && str[i] && str)
			i++;
	while (ft_isspace(str[i]) && str[i] && str)
	{
		num_space++;
		i++;
	}
	return (num_space);
}
