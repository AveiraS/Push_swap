/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:47:40 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 17:43:47 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char		*ft_strndup(const char *str, int start, int end)
{
	int		i;
	int		length;
	char	*ptr;

	i = 0;
	length = end - start;
	ptr = (char*)malloc(sizeof(char) * (length + 2));
	if (!ptr)
		return (NULL);
	while (start <= end && str[start + 1] != '\0')
	{
		ptr[start] = str[start];
		start++;
	}
	ptr[start] = '\0';
	return (ptr);
}
