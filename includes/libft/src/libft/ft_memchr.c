/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:13:05 by asmall            #+#    #+#             */
/*   Updated: 2019/10/30 22:50:34 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void *a;

	a = (void*)s;
	while (n > 0)
	{
		if (*((unsigned char *)a) == (unsigned char)c)
			return (a);
		a++;
		n--;
	}
	return (NULL);
}
