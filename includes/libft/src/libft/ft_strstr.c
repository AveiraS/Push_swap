/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:05:22 by asmall            #+#    #+#             */
/*   Updated: 2019/10/30 23:01:05 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char		*ft_strstr(const char *dst, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*src == '\0')
		return ((char*)dst);
	while (dst[i])
	{
		j = 0;
		while (src[j])
		{
			if (dst[i + j] == src[j])
				j++;
			else
				break ;
			if (src[j] == '\0')
				return ((char*)dst + i + j - ft_strlen(src));
		}
		i++;
	}
	return (NULL);
}
