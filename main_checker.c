/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:10:43 by asmall            #+#    #+#             */
/*   Updated: 2019/11/30 16:24:55 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Создаём структуру, помещаем в неё данные через аргументы параметры
*/

static t_stack	*creat_lst(int *stack_a, int size)
{
	t_stack		*lst_stac;
	t_stack		*cur_value;
	int			i;
	int			pos;

	i = 0;
	pos = 0;
	lst_stac = NULL;
	while (i < size)
	{
		if (!(cur_value = (t_stack*)malloc(sizeof(t_stack))))
			break ;
		cur_value->value = stack_a[i];
		cur_value->next = NULL;
		cur_value->pos = pos++;
		add_to_stack(&lst_stac, cur_value);
		i++;
	}
	free(stack_a);
	return ((cur_value != NULL) ? lst_stac : NULL);
}

/*
** Проверка структуры на правильность сортировки, каждое значение
** должно быть меньше, чем следующее. Если структура не существует,
** или сортировка не верная, то программа возвращает ошибку
*/

static int		check_order_lst(int size, t_stack *a, t_stack *b)
{
	int			i;

	i = 0;
	if (b != NULL)
	{
		free_stack_list(b);
		return (1);
	}
	while (i < (size - 1))
	{
		if (a->value > (a->next)->value)
			return (1);
		a = a->next;
		i++;
	}
	return (0);
}

/*
** С помощью GNL функция принимает значения опций, которые применяет
** для сортировки полученной структуры.
** check_order_lst: проверяет отсортированный список
*/

static void		checker(int *stack_a, int size, t_op *val)
{
	t_stack		*a;
	t_stack		*b;
	char		*op;

	if (stack_a != NULL)
	{
		if (!(stack_a = get_min_max_middle(val, stack_a, size)))
			return ;
		if (!(a = creat_lst(stack_a, size)))
		{
			free_stack_list(a);
			return ;
		}
		free(val->order);
	}
	b = NULL;
	while (get_next_line(0, &op) == 1)
	{
		choose_op(&a, &b, op);
		(val->v_flag == 1) ? ft_v(a, b, val, op) : NULL;
		free(op);
	}
	(check_order_lst(size, a, b) == 0) ? ft_printf("OK\n") : ft_printf("KO\n");
	free_stack_list(a);
}

/*
** Подключает флаг визуализации
*/

static void		visual_flag(char ***argv, t_op *val)
{
	char		*ptr;

	if (ft_strcmp((*argv)[1], "-v") == 0)
	{
		(*argv)++;
		ptr = val->line;
		ft_chr_and_fill(&ptr, '-', 30);
		val->v_flag = 1;
	}
	else
		val->v_flag = 0;
}

int				main(int argc, char **argv)
{
	t_op		val;
	int			*stack_a;
	int			size;

	size = -2;
	stack_a = NULL;
	if (argc == 1 || check_args(argv, argc) == 0)
		return (0);
	visual_flag(&argv, &val);
	(argc >= 2) ? size = parse_stack(argv, &stack_a, 'c') : 1;
	(size == -1) ? (ft_printf("Error\n")) : (checker(stack_a, size, &val));
	return (0);
}
