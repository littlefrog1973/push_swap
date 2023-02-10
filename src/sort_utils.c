/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:09:06 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/09 14:12:38 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	(*a).stack = ft_calloc(argc - 1, sizeof(int));
	if (!(*a).stack)
		err_exit(2);
	while (i + 1 < argc)
	{
		(*a).stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	(*a).size = argc - 1;
	(*b).stack = ft_calloc(argc - 1, sizeof(int));
	if (!(*b).stack)
	{
		free((*a).stack);
		err_exit(2);
	}
	(*b).size = 0;
	return (1);
}

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

char	*init_record(int n)
{
	char	*rec;

	rec = (char *) ft_calloc((size_t) n * log_base2(n) * 3, sizeof(char));
	if (!rec)
		return (NULL);
	return (rec);
}

void	free_stack(t_stack *a, t_stack *b)
{
	free((*a).stack);
	free((*b).stack);
}
/*
int	main(void)
{
	ft_printf("log2(8) = %d\n", log_base2(8));
}
*/
