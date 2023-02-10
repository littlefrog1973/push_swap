/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:34:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/10 00:53:19 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_out(char *rec)
{
	int		i;
	char	tag[11][4];

	ft_memcpy(tag,
		"sa\0\0sb\0\0ss\0\0pa\0\0pb\0\0ra\0\0rb\0\0rr\0\0rra\0rrb\0rrr\0", 44);
	i = 0;
	while (rec[i])
	{
		ft_printf("%s\n", tag[rec[i] - SA]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*rec;

	if (argc == 1)
		exit(1);
	if (check_argv(argc, argv))
		rec = sorting(argc, argv);
	else
	{
		ft_printf("Data is OK but sorted\n");
		return (0);
	}
	if (*rec)
		print_out(rec);
	if (rec && *rec)
		free(rec);
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
