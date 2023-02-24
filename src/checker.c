/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:13:37 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/24 10:53:42 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
// Main function for checker program
{
	int		check_result;
	char	dummy[2];
	char	*order;
	t_stack	a;
	t_stack	b;

	order = "";
	ft_memset(dummy, 0, 2);
	check_result = 0;
	if (!check_argv(argc, argv) || argc == 1)
		return (0);
	else
	{
		if (!init_stack(argc, argv, &a, &b))
			err_exit(2);
		else
			check_result = checking(&a, &b, dummy, order);
	}
	free_stack(&a, &b);
	if (check_result == ASC)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
