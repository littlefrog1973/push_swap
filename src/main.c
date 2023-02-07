/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:34:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/07 08:28:46 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc > 2)
		check_argv(argc, argv);
	else if (argc == 2 && is_all_digit(argv))
		return (1);
	else if (argc == 1)
		exit(1);
	else
		err_exit(1);
	return (0);
}
/*	ft_printf("INT_MIN - 2 = %d\n", INT_MIN - 2 * (INT_MIN));
	ft_printf("6442450941 = %d\n", ft_atoi("6442450941"));
	ft_printf("INT_MAX = %d\n", atoi("2147483647"));
	ft_printf("2*INT_MAX = %d\n", atoi("4294967294"));
	ft_printf("3*INT_MAX = %d\n", atoi("6442450941"));
	ft_printf("4*INT_MAX = %d\n", atoi("8589934588"));
	ft_printf("4*INT_MAX + 5 = %d\n", atoi("8589934593"));
	ft_printf("9999999999 = %d\n", atoi("9999999999"));
	ft_printf("INT_MIN = %d\n", atoi("-2147483648"));
	ft_printf("2*INT_MIN = %d\n", atoi("-4294967296"));
	ft_printf("3*INT_MIN = %d\n", atoi("-6442450944"));
	ft_printf("4*INT_MIN = %d\n", atoi("-8589934592"));
	ft_printf("4*INT_MIN + 5 = %d\n", atoi("-8589934587"));
	ft_printf("-9999999999 = %d\n", atoi("-9999999999"));
*/
