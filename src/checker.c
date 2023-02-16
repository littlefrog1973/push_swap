/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 06:13:37 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/16 12:43:43 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
//		ft_printf("Data is OK but sorted\n");
{
	int	check_result;
	char dummy[2];

	ft_memset(dummy, 0, 2);
	if (argc == 1)
		exit(1);
	if (check_argv(argc, argv))
		check_result = checking(argc, argv, dummy);
	else
		return (0);
	if (check_result == ASC)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
