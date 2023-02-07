/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:50:10 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:40:33 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*running;
	int		num_list;

	running = lst;
	num_list = ft_lstsize(lst);
	new = NULL;
	if (!num_list)
		return ((t_list *) NULL);
	while (num_list > 0)
	{
		tmp = ft_lstnew(f(running->content));
		running = running->next;
		ft_lstadd_back(&new, tmp);
		num_list--;
	}
	if (ft_lstsize(lst) != ft_lstsize(new))
		ft_lstclear(&new, (del));
	return (new);
}
