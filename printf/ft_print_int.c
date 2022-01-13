/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:06:20 by wocho             #+#    #+#             */
/*   Updated: 2022/01/13 19:06:29 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list ap, t_sett *sett)
{
	int		val;
	int		min;
	int		count;
	char	*result;

	val = va_arg(ap, int);
	if (val == 0 && sett->precision == 0 && sett->width == 0)
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
	if (sett->flag & FLAG_LEFT)
		left_justify(result, count);
	write(1, result, count);
	free(result);
	return count;
}	
