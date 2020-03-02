/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:15:56 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 23:27:01 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void		output_alig(int a_size, int b_size, int size)
{
	int			cr;

	if (a_size >= b_size)
		cr = size - a_size;
	else if (b_size > a_size)
		cr = size - b_size;
	else
		cr = 0;
	while (cr > 0)
	{
		ft_printf("\n");
		cr--;
	}
}

static void		b_side_output(t_stack **b, t_op *val, int len, int *b_size)
{
	const char	*format;
	int			sp;

	ft_printf("%.*s", len, val->spaces);
	if ((sp = val->pow - take_power((*b)->pos)) > 0)
		ft_printf("%.*s", sp, val->spaces);
	if (*b && (*b)->next && (((*b)->next)->pos - (*b)->pos == 1))
		format = "\033[01;38;05;77m%d %.*s\033[0m\n";
	else if (*b && (*b)->prev && ((*b)->pos - ((*b)->prev)->pos == 1))
		format = "\033[01;38;05;77m%d %.*s\033[0m\n";
	else
		format = "%d %.*s\n";
	ft_printf(format, (*b)->pos, (*b)->pos, val->bloc);
	*b = (*b)->next;
	(*b_size)--;
}

static int		a_side_output(t_stack **a, t_op *val,
				int *a_size, int *b_size)
{
	const char	*format;
	int			sp;
	int			len;

	len = 0;
	if ((*a)->pos == val->size_a + val->size_b)
		format = "\033[01;38;05;199m%d %.*s\033[0m";
	else if (*a && (*a)->next && (((*a)->next)->pos - (*a)->pos == 1))
		format = "\033[01;38;05;77m%d %.*s\033[0m";
	else if (*a && (*a)->prev && ((*a)->pos - ((*a)->prev)->pos == 1))
		format = "\033[01;38;05;77m%d %.*s\033[0m";
	else
		format = "%d %.*s";
	if ((sp = val->pow - take_power((*a)->pos)) > 0)
		len = ft_printf("%.*s", (sp), val->spaces);
	len += ft_printf(format, (*a)->pos, (*a)->pos, val->bloc);
	if (*format == '\033')
		len -= ((*a)->pos == val->size) ? 19 : 18;
	if (*a_size > *b_size)
		ft_printf("\n");
	*a = (*a)->next;
	(*a_size)--;
	return (len);
}

void			ft_vz(t_stack *a, t_stack *b, t_op *val, char *opt)
{
	const char	*speed;
	int			len;
	int			sz;
	int			a_size;
	int			b_size;

	speed = (val->size < 70) ? "sleep 0.07" : "sleep 0.01";
	a_size = val->size_a;
	b_size = val->size_b;
	sz = val->size + 30;
	system(speed);
	system("clear");
	output_alig(a_size, b_size, val->size);
	while (a_size > b_size && a)
		a_side_output(&a, val, &a_size, &b_size);
	while (a_size < b_size && b)
		b_side_output(&b, val, sz, &b_size);
	while (b_size > 0 && a_size > 0 && a && b)
	{
		len = a_side_output(&a, val, &a_size, &b_size);
		b_side_output(&b, val, (sz - len), &b_size);
	}
	ft_printf("CMD: %s", opt);
}

void			ft_v(t_stack *a, t_stack *b, t_op *val, char *opt)
{
	int			count_a;
	int			count_b;

	count_a = 0;
	count_b = 0;
	val->size_a = (int)(ft_lstcount(a));
	val->size_b = (int)(ft_lstcount(b));
	ft_printf("{green}%s{eoc}\n\n", val->line);
	ft_printf("       Command - %s\n", opt);
	ft_printf("%s", "   STACK A:      STACK B:  \n");
	ft_printf(" ____________   ____________ \n");
	while (count_a < val->size_a || count_b < val->size_b)
	{
		(count_a++ < val->size_a) ? ft_printf("|% 11d | ", a->value)
			: ft_printf("|            | ");
		a = (count_a <= val->size_a) ? (a->next) : 0;
		(count_b++ < val->size_b) ? ft_printf("|% 11d | \n", b->value)
			: ft_printf("|            | \n");
		b = (count_b <= val->size_b) ? (b->next) : 0;
		ft_printf("|____________| |____________|\n");
	}
	(ft_printf("\n"));
}
