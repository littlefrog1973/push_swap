/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:38:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/12/19 16:58:58 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	check_new_line(char *buffer)
/* Check whether new_line in buffer or not, if yes: return its position */
{
	ssize_t	i;

	i = 0;
	while (*(buffer + i) != '\n' && *(buffer + i))
		i++;
	if (*(buffer + i) == '\n')
		return (i);
	else
		return (-1);
}
