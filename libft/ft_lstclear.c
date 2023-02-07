/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:27:47 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/07/22 11:19:42 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*to_delete;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		del(tmp->content);
		to_delete = tmp;
		tmp = tmp->next;
		free(to_delete);
	}
	del(tmp->content);
	free(tmp);
	*lst = NULL;
}
