/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:05:18 by wocho             #+#    #+#             */
/*   Updated: 2022/01/13 18:58:10 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_atoi(char **s_ptr)
{
	long	result;
	long	prev;
	char	*str;

	str = *s_ptr;
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		prev = result;
		result = result * 10 + *str - '0';
		if (prev > result / 10)
			return ((int)LONG_MIN);
		str++;
	}
	*s_ptr = str;
	return ((int)(result));
}

void	init_sett(t_sett *sett)
{
	sett->flag = 0;
	sett->width = 0;
	sett->precision = 1;
}

int	get_type(char *s)
{
	if (*s == 'd' || *s == 'i')
		return (0);
	else if (*s == 'u')
		return (1);
	else if (*s == 'x' || *s == 'X' || *s == 'p')
		return (2);
	else if (*s == 'c')
		return (3);
	else if (*s == 's')
		return (4);
	else if (*s == '%')
		return (5);
	return (-1);
}

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