/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:07:57 by sdeeyien          #+#    #+#             */
/*   Updated: 2023/02/15 13:31:24 by sdeeyien         ###   ########.fr       */
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

# define SA 'a'
# define SB 'b'
# define SS 'c'
# define PA 'd'
# define PB 'e'
# define RA 'f'
# define RB 'g'
# define RR 'h'
# define RRA 'i'
# define RRB 'j'
# define RRR 'k'
# define ASC 1
# define DSC -1

/*check_argv.c*/
int		check_argv(int argc, char **argv);
int		is_all_digit(char **a);
int		is_overflow(char **a);
int		is_sort_char(char **argv);

/*utils.c*/
void	err_exit(int err_no);
size_t	n_digit(int number);
int		n_spc(char *str);
int		n_pls(char *str);
int		n_mns(char *str);

/*sort.c*/
char	*sorting(int argc, char **argv);
int		is_sort(t_stack *a);
int		sort_low_n(t_stack *a, t_stack *b, char *rec);
int		bubble_sort_a(t_stack *a, char *rec, int direction);

/*sort_utils.c*/
int		init_stack(int argc, char **argv, t_stack *a, t_stack *b);
char	*init_record(int argc);
void	free_stack(t_stack *a, t_stack *b);
int		find_min(t_stack *a);
int		find_max(t_stack *b);

/*sort_utils2.c*/
int		log_base2(int n);

/*stack1.c*/
int		sa(t_stack *a, char *rec);
int		sb(t_stack *b, char *rec);
int		ss(t_stack *a, t_stack *b, char *rec);
int		pa(t_stack *a, t_stack *b, char *rec);
int		pb(t_stack *a, t_stack *b, char *rec);

/*stack2.c*/
int		ra(t_stack *a, char *rec);
int		rb(t_stack *a, char *rec);
int		rr(t_stack *a, t_stack *b, char *rec);

/*stack3.c*/
int		rra(t_stack *a, char *rec);
int		rrb(t_stack *a, char *rec);
int		rrr(t_stack *a, t_stack *b, char *rec);

/*sort_algo.c*/
int		sort_two(t_stack *a, char *rec);
int		sort_three(t_stack *a, char *rec);
int		sort_four(t_stack *a, t_stack *b, char *rec);
int		sort_five(t_stack *a, t_stack *b, char *rec);

/*sort_algo2.c*/
int		is_sort_circle(t_stack *a);
int		swap_circle_a(t_stack *a, char *rec, int direction);
int		move_to_top_a(t_stack *a, int i, char *rec);
int		is_disorder_circle(t_stack *a, int i);

/*sort_algo3.c*/
int		sort_hi_n(t_stack *a, t_stack *b, char *rec);

/*sort_algo4.c*/
int		move_to_top_b(t_stack *a, int i, char *rec);
int		swap_circle_b(t_stack *a, char *rec, int direction);
int		bubble_sort_b(t_stack *a, char *rec, int direction);
#endif
