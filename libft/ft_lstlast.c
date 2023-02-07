/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:57:32 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:40:13 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node0;
	char	*str = "abc";
	t_list	*node1;
	t_list	**head;
	t_list	*current;

	head = NULL;	
	node0 = ft_lstnew((char *) str);
	head = &node0;
	node1 = ft_lstnew((char *) "def");
	ft_lstadd_front(head, node1);
	printf("number of node = %d\n", ft_lstsize(node1));
	printf("number of node[NULL] = %d\n", ft_lstsize(NULL));
	current = ft_lstlast(node1);
	printf("current(last)->content = %s\n",current->content);
	
	t_list	*l = ((void *) 0);
	t_list	*expected;
	t_list	*actual;
	
	expected = ((void *) 0);
	actual = ft_lstlast(l);
	if (actual == expected)
		printf("even NULL list is OK\n");
	else
		printf("NULL list is not OK\n");
	return (0);
}*/
