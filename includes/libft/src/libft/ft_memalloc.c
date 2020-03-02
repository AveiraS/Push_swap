/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:30:06 by asmall            #+#    #+#             */
/*   Updated: 2019/10/30 22:50:30 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		ptr[i++] = ' ';
	ptr[i] = '\0';
	return (ptr);
}
