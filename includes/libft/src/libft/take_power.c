/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:34:24 by asmall            #+#    #+#             */
/*   Updated: 2020/02/10 18:09:47 by asmall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		take_power(int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}