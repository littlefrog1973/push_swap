/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:09:06 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/14 15:34:21 by sdeeyien         ###   ########.fr       */
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

char	*init_record(int n)
//	rec = (char *) ft_calloc((size_t) n * log_base2(n) * 10, sizeof(char));
{
	char	*rec;

	rec = (char *) ft_calloc((size_t) n * n * 10, sizeof(char));
	if (!rec)
		return (NULL);
	return (rec);
}

void	free_stack(t_stack *a, t_stack *b)
{
	free((*a).stack);
	free((*b).stack);
}

int	find_max(t_stack *a)
{
	int	i;
	int	dummy;
	int	pos;

	i = 0;
	dummy = INT_MIN;
	pos = 0;
	while (i < (*a).size)
	{
		if (dummy <= (*a).stack[i])
		{
			dummy = (*a).stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	find_min(t_stack *a)
{
	int	i;
	int	dummy;
	int	pos;

	i = 0;
	dummy = INT_MAX;
	pos = 0;
	while (i < (*a).size)
	{
		if (dummy >= (*a).stack[i])
		{
			dummy = (*a).stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
/*
int	main(void)
{
	t_stack	a;
	int		vec[] = {INT_MIN + 1, INT_MIN + 3, INT_MIN+5, INT_MIN};

	a.stack = vec;
	a.size = 4;
	ft_printf("offset of max value = %d\n", find_max(&a));
	ft_printf("offset of max value = %d\n", find_min(&a));
	return (0);
}
*/
