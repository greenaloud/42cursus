/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:05:18 by wocho             #+#    #+#             */
/*   Updated: 2022/01/12 16:39:46 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_atoi(char **s_ptr)
{
	int		sign;
	long	result;
	long	prev;
	char	*str;

	str = *s_ptr;
	sign = 1;
	result = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		prev = result;
		result = result * 10 + *str - '0';
		if (prev != result / 10 && sign == -1)
			return ((int)LONG_MIN);
		if (prev != result / 10 && sign == 1)
			return ((int)LONG_MAX);
		str++;
	}
	*s_ptr = str;
	return ((int)(sign * result));
}

void	init_sett(t_sett *sett)
{
	sett->flag = 0;
	sett->width = 0;
	sett->precision = 0;
}
