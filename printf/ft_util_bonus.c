/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:13:09 by wocho             #+#    #+#             */
/*   Updated: 2022/01/15 12:13:13 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	left_justify(char *str, int len)
{
	int	idx;
	int	move;

	idx = 0;
	while (str[idx] == ' ')
		idx++;
	if (idx == 0)
		return ;
	move = idx;
	while (idx < len)
	{
		str[idx - move] = str[idx];
		idx++;
	}
	idx = len - move;
	while (idx < len)
	{
		str[idx] = ' ';
		idx++;
	}
}

void	fill_zero(char *result, t_sett *sett, int *last, int *len)
{
	while (*len < sett->precision)
	{
		result[*last] = '0';
		(*last)--;
		(*len)++;
	}
	if (sett->flag & FLAG_ZERO)
	{
		if (sett->flag & FLAG_SIGN)
			(*len)++;
		while (*len < sett->width)
		{
			result[*last] = '0';
			(*last)--;
			(*len)++;
		}
	}
}

int	write_and_return(char *result, int count)
{
	count = write(1, result, count);
	free(result);
	return (count);
}
