/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:32:44 by wocho             #+#    #+#             */
/*   Updated: 2022/01/13 20:16:37 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(va_list ap, t_sett *sett)
{
	int		len;
	int		size;
	int		idx;
	char	*val;
	char	*result;

	val = va_arg(ap, char *);
	if (val == NULL)
		val = "(null)";
	len = 0;
	while (val[len])
		len++;
	if (sett->flag & FLAG_PRECISION && sett->precision < len)
		len = sett->precision;
	size = len;
	if (sett->width > len)
		size = sett->width;
	result = malloc(sizeof (char) * size);
	if (result == NULL)
		return (0);
	if (sett->flag & FLAG_LEFT)
	{
		idx = 0;
		while (idx < len)
		{
			result[idx] = val[idx];
			idx++;
		}
		while (idx < size)
		{
			result[idx] = ' ';
			idx++;
		}
	}
	else
	{
		idx = size - len;
		while (idx < size)
		{
			result[idx] = val[idx - (size - len)];
			idx++;
		}
		idx = 0;
		while (idx < size - len)
		{
			result[idx] = ' ';
			idx++;
		}
	}
	write(1, result, size);
	free(result);
	return (size);
}
