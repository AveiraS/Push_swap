/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_int_mass.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:55:02 by asmall            #+#    #+#             */
/*   Updated: 2019/10/30 22:49:41 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		*creat_int_mass(int size)
{
	int	*result;
	int	i;

	i = 0;
	result = (int*)malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	while (i < size)
		result[i++] = 0;
	return (result);
}
