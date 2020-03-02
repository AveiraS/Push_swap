/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:48:23 by asmall            #+#    #+#             */
/*   Updated: 2019/10/30 23:02:49 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

unsigned long long	to_power(unsigned long long a, int power)
{
	if (power == 0)
		return (1);
	a = a * to_power(a, power - 1);
	return (a);
}
