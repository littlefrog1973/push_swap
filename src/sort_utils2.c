/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:27:08 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/10 23:28:13 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	log_base2(int n)
{
	int	dummy;
	int	i;

	i = 0;
	dummy = 1;
	if (n == 1)
		return (0);
	while (dummy < n)
	{
		dummy = dummy << 1;
		i++;
	}
	return (i);
}
