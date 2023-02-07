/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:59:46 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:18:41 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*running;

	if (*lst == NULL && new != NULL)
	{
		*lst = new;
	}
	else if (new != NULL)
	{
		running = *lst;
		while (running->next != NULL)
			running = running->next;
		running->next = new;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*node0;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	**head;
	t_list	**current;
	int	i;

	head = NULL;
	current = NULL;
	node0 = ft_lstnew((void *) 0);
	node1 = ft_lstnew((void *) 1);
	node2 = ft_lstnew((void *) 2);
	node3 = ft_lstnew((void *) 3);
	node4 = ft_lstnew((void *) 4);
	printf("made individual list complete\n"); 

	head = (t_list **) calloc(sizeof(t_list *), 1);
	current = (t_list **) calloc(sizeof(t_list *), 1);
	ft_lstadd_back(head, node0);
	printf("added 0th node\n"); 
	ft_lstadd_back(head, node1);
	printf("added 1nd node\n"); 
	ft_lstadd_back(head, node2);
	printf("added 2rd node\n"); 
	ft_lstadd_back(head, node3);
	printf("added 3th node\n"); 
	ft_lstadd_back(head, node4);
	printf("added 4th node\n"); 
	printf("node 4->content = %d\n",*(int *) (node4->content));
	printf("head's content = %d\n", *(int *) ((*head)->content));
	i = 0;
	current = head;
	while ((*current != NULL))
	{
		printf("node %d = %s\n", i, (char *) (*current)->content);
		*current = (*current)->next;
		i++;
	}
	return (0);
}*/
