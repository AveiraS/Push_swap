/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:05:49 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 20:56:56 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
** Подключение флагов визуализации. Проверка правильности написания флагов.
** Функция возвращает ошибку при написании двух флагов одновременно.
*/

static int		bonus_flag(char **args, t_op *val)
{
	char		*tmp;

	if (args[2] && (ft_strcmp(args[2], "-v") == 0
		|| ft_strcmp(args[2], "-vz") == 0))
		return (-1);
	if (ft_strcmp(args[1], "-v") == 0)
	{
		val->v_flag = 1;
		tmp = (val)->line;
		ft_chr_and_fill(&tmp, '_', 30);
	}
	else if (ft_strcmp(args[1], "-vz") == 0)
	{
		val->v_flag = 2;
		tmp = (val)->bloc;
		ft_chr_and_fill(&tmp, '_', 200);
		tmp = (val)->spaces;
		ft_chr_and_fill(&tmp, ' ', 200);
	}
	return (0);
}

/*
** check_args: проверка на наличии входных параметров
** parse_stack: проверка валидности параметров, заполнение stack_a
** push_swap: основная функция сортировки стеков
*/

int				main(int argc, char **argv)
{
	t_op		val;
	int			*stack_a;

	stack_a = NULL;
	val.v_flag = 0;
	if (argc == 1 || check_args(argv, argc) == 0)
		return (ft_printf("Error\n"));
	if (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[1], "-vz") == 0)
	{
		if ((bonus_flag(argv, &val) == -1) ||
		(argc == 2 || (argc == 3 && argv[2][0] == '\0')))
			return (ft_printf("Error\n"));
		argv++;
	}
	val.size = parse_stack(argv, &stack_a, 'p');
	val.pow = take_power(val.size);
	(val.size > 0) ? push_swap(stack_a, val.size, &val) : ft_printf("Error\n");
	return (0);
}
