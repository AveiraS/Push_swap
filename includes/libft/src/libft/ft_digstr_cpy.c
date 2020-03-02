/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digstr_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:23:39 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 22:34:23 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int			*ft_digstr_cpy(int *stack, int size)
{
	int		*s_a;
	int		i;

	i = 0;
	s_a = NULL;
	s_a = (int*)malloc(sizeof(int) * size);
	if (!s_a)
		return (NULL);
	while (i < size)
	{
		s_a[i] = stack[i];
		i++;
	}
	return (s_a);
}
