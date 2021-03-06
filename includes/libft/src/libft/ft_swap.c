/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:47:26 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 17:43:10 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		ft_swap(int *stack, int l, int r)
{
	int		tmp;

	tmp = stack[l];
	stack[l] = stack[r];
	stack[r] = tmp;
}
