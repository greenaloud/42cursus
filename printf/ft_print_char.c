/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:09:18 by wocho             #+#    #+#             */
/*   Updated: 2022/01/13 19:27:30 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap, t_sett *sett)
{
	int		len;
	int		idx;
	char	val;
	char	*result;

	val = va_arg(ap, int);
	len = 1;
	if (sett->width > 1)
		len = sett->width;
	else if (sett->width == 0)
	{
		write(1, &val, 1);
		return (1);
	}
	result = malloc(sizeof (char) * len);
	if (result == NULL)
		return (0);
	if (sett->flag & FLAG_LEFT)
	{
		idx = 0;
		result[idx++] = val;
		while (idx < len)
			result[idx++] = ' ';
	}
	else
	{
		idx = len - 1;
		result[idx--] = val;
		while (idx >= 0)
			result[idx--] = ' ';
	}
	write(1, result, len);
	free(result);
	return (len);
}
