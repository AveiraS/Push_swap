/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:39:57 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 14:40:03 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/headers/libft.h"

typedef struct		s_stack
{
	int				value;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef	struct		s_op
{
	int				min;
	int				second_min;
	int				middle;
	int				max;
	int				size_a;
	int				size_b;
	int				v_flag;
	int				size;
	int				pow;
	int				*order;
	char			bloc[200];
	char			line[30];
	char			spaces[200];
}					t_op;

typedef struct		s_actions
{
	int				a_pos;
	int				b_pos;
	int				move_a;
	int				move_b;
	t_op			*val;
}					t_actions;

/*
** ***********************  operators.c  ******************************
*/

void				option_s(t_stack **stack);
void				option_p(t_stack **stack_a, t_stack **stack_b);
void				option_r(t_stack **stack);
void				option_rr(t_stack **stack);
void				run_together(t_stack **stack_a, t_stack **stack_b,
						void(function)(t_stack **));

/*
** ************************ parse_stack_a.c  ****************************
*/

int					parse_stack(char **a, int **stack_a, char programm);

/*
** ************************ choose_op.c  ********************************
*/

void				choose_op(t_stack **a, t_stack **b, char *op);
void				take_stack_op(t_stack **a, t_stack **b, t_op *val,
						char *opt);

/*
** ************************ create_lst_stack.c **************************
*/

t_stack				*stack_as_list(int *stack_a, int *order, int size);
size_t				ft_lstcount(t_stack *lst);
void				free_stack_list(t_stack *stac);
void				add_to_stack(t_stack **alst, t_stack *new);

/*
** ************************** bonus.c ************************************
*/

void				ft_vz(t_stack *a, t_stack *b, t_op *val, char *opt);
void				ft_v(t_stack *a, t_stack *b, t_op *val, char *opt);

/*
** *************************  push_swap.c ********************************
*/
int					push_swap(int *stack_a, int size, t_op *val);

/*
** ************************** general_sort.c ***************************
*/

void				sorting_inserts(t_stack **a, t_stack **b, t_op *val,
						int size);

/*
** **************************** three_or_five.c ***************************
*/

void				sort_little_count(t_stack **a, t_stack **b,
						t_op *val, int size);

/*
** *****************************  get_min_and_middle.c  *******************
*/

int					*get_min_max_middle(t_op *val, int *stack_a, int size);
int					check_args(char **args, int argc);

#endif
