/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:45:20 by wocho             #+#    #+#             */
/*   Updated: 2022/01/12 18:59:55 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list ap, t_sett *sett)
{
	int		val;
	int		min;
	int		count;
	char	*result;

	val = va_arg(ap, int);
	if (val == 0 && sett->precision == 0)
		return (0);
	if (sett->width > sett->precision)
		min = sett->width;
	else
	{
		min = sett->precision;
		if (val < 0 || sett->flag & FLAG_SPACE || sett->flag & FLAG_PLUS)
		{
			min++;
			sett->flag |= FLAG_COMB;
		}
	}
	result = ft_itoa(val, min, sett, &count);
	write(1, result, count);
	free(result);
	return count;
}	
