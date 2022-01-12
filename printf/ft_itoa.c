/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:06:28 by wocho             #+#    #+#             */
/*   Updated: 2022/01/12 18:58:42 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	convert(char *result, long num, int last, t_sett *sett)
{
	char	sign;
	int 	len;

	len = 0;
	sign = '+';
	if (num < 0)
	{
		sign = '-';
		num *= -1;
	}
	if (num == 0 && sett->precision != 0)
	{
		len++;
		result[last--] = '0';
	}
	while (num > 0)
	{
		result[last--] = num % 10 + '0';
		num /= 10;
		len++;
	}
	while (len < sett->precision)
	{
		result[last--] = '0';
		len++;
	}
	if (sett->precision == -1 && !(sett->flag & FLAG_LEFT) && sett->flag & FLAG_ZERO)
	{
		if (sett->flag & FLAG_COMB)
			len++;
		while (len < sett->width)
		{
			result[last--] = '0';
			len++;
		}
	}
	if (sign == '-' || sett->flag & FLAG_PLUS)
		result[last--] = sign;
	else if (sett->flag & FLAG_SPACE)
		result[last--] = ' ';
	while (last >= 0)
		result[last--] = ' ';
}

char	*ft_itoa(int n, int min, t_sett *sett, int *count)
{
	int		len;
	int		size;
	int		temp;
	char	*result;

	size = 0;
	if (n == 0 || sett->flag & FLAG_COMB)
		size++;
	temp = n;
	while (temp != 0)
	{
		size++;
		temp /= 10;
	}
	if (min > size)
		size = min;
	*count = size;
	result = malloc(sizeof (*result) * size);
	if (result == NULL)
		return (NULL);
	convert(result, n, size - 1, sett);
	return (result);
}
