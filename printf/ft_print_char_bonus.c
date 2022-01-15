/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:09:02 by wocho             #+#    #+#             */
/*   Updated: 2022/01/15 12:09:08 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	fill_left(char *result, char val, int len)
{
	int	idx;

	result[0] = val;
	idx = 1;
	while (idx < len)
	{
		result[idx] = ' ';
		idx++;
	}
}

static void	fill_right(char *result, char val, int len)
{
	int	idx;

	result[len - 1] = val;
	idx = len - 2;
	while (idx >= 0)
	{
		result[idx] = ' ';
		idx--;
	}
}

int	print_char(va_list ap, t_sett *sett)
{
	int		len;
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
		return (-1);
	if (sett->flag & FLAG_LEFT)
		fill_left(result, val, len);
	else
		fill_right(result, val, len);
	return (write_and_return(result, len));
}
