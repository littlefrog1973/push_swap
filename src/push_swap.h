/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/07 08:09:40 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# include "../libft/libft.h"

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

int	check_argv(int argc, char **argv);
void err_exit(int err_no);
size_t	n_digit(int number);
int	n_spc(char *str);
int	n_pls(char *str);
int	n_mns(char *str);
int	is_all_digit(char **a);

#endif
