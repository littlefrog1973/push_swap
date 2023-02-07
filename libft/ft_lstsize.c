/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:08:38 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:46:44 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst == NULL)
		return (0);
	else
	{
		i = 0;
		while (lst->next != NULL)
		{	
			lst = lst->next;
			i++;
		}
	}
	return (i + 1);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node0;
	char	*str = "abc";
	t_list	*node1;
	t_list	**head;

	node0 = NULL;
	printf("node0's size (NULL) = %d\n", ft_lstsize(node0));	
	node0 = ft_lstnew((char *) str);
	head = &node0;
	node1 = ft_lstnew((char *) "def");
	ft_lstadd_front(head, node1);
	printf("number of node = %d\n", ft_lstsize(*head));
	printf("number of node[NULL] = %d\n", ft_lstsize(NULL));
	return (0);
}*/
