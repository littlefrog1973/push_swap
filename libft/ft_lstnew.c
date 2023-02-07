/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:55:03 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:46:22 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*new_node;
	t_list	*new_node2;
	t_list	**head;
	t_list	**current;
	char	*str = "abc";

	new_node = ft_lstnew((void *) str);
	printf("new_node's content = %s\n", new_node->content);
	new_node2 = ft_lstnew((void *) "def");
	printf("new_node2's content = %s\n", new_node2->content);
	head = &new_node;
	new_node->next = new_node2;
	new_node2->next = NULL;
	current = head;

	while (*current->next != NULL)
	{
	printf("list content = %s\n", current->content);
	current = current->next;
	}
	return (0);
}*/	
