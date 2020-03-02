/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:42:03 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 20:09:04 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Добавляем новый элемент в структуру
*/

void			add_to_stack(t_stack **alst, t_stack *new)
{
	t_stack		*ptr;

	ptr = *alst;
	if (!ptr)
	{
		*alst = new;
		(*alst)->prev = NULL;
	}
	else
	{
		if (ptr->prev != NULL)
			ptr = ptr->prev;
		ptr->next = new;
		new->next = NULL;
		new->prev = ptr;
		(*alst)->prev = new;
	}
}

/*
** Создаём двунаправленную структуру: value: цифра, pos: место при сортировке
** stack_a не отсортирован, order отсортирован
** Функция возвращает готовый список из заданных цифр с позициями для сортировки
*/

t_stack			*stack_as_list(int *stack_a, int *order, int size)
{
	t_stack		*lst_stac;
	t_stack		*cur_value;
	int			i;
	int			pos;

	i = 0;
	lst_stac = NULL;
	while (i < size)
	{
		if (!(cur_value = (t_stack*)malloc(sizeof(t_stack))))
			return (NULL);
		pos = 0;
		cur_value->value = stack_a[i];
		cur_value->next = NULL;
		while (cur_value->value != order[pos])
			pos++;
		cur_value->pos = pos + 1;
		add_to_stack(&lst_stac, cur_value);
		i++;
	}
	free(order);
	free(stack_a);
	return (lst_stac);
}

/*
** Удаляем структуру
*/

void			free_stack_list(t_stack *stac)
{
	t_stack		*ptr;

	if (!stac)
		return ;
	while (stac != NULL)
	{
		ptr = stac->next;
		free(stac);
		stac = ptr;
	}
}

/*
** Считает количество элементов структуры
*/

size_t			ft_lstcount(t_stack *lst)
{
	size_t		i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
