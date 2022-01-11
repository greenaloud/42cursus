/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:45:20 by wocho             #+#    #+#             */
/*   Updated: 2022/01/11 20:07:41 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_integer(va_list ap, t_sett *sett)
{
	int		val;
	int		min;
	char	*result;

	val = va_arg(ap, int);
	if (sett->width > sett->precision)
		min = sett->width;
	else
		min = sett->precision;
	result = ft_itoa(val, min, sett);	
