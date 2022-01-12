/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:36:54 by wocho             #+#    #+#             */
/*   Updated: 2022/01/12 19:04:13 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
			s = print_param((char *)s, ap, &count);
		else
			s += print_string((char *)s, &count);
	}
	va_end(ap);
	return (count);
}

int	print_string(char *s, int *count)
{
	int	idx;

	idx = 0;
	while (s[idx] && s[idx] != '%')
		idx++;
	write(1, s, idx);
	*count += idx;
	return (idx);
}

char	*print_param(char *s, va_list ap, int *count)
{
	int		type;
	t_sett	sett;

	init_sett(&sett);
	s = get_setting(++s, &sett);
	s = get_width(s, &sett);
	s = get_precision(s, &sett);
	int ret = print_integer(ap, &sett);
	s++;
	return (s);
}

int	main(void)
{
	ft_printf("|%+4.6d", 22);
	printf("|\n");
	ft_printf("|%+4.6d", 2222222);
	printf("|\n");
	ft_printf("|%+8.6d", -22);
	printf("|\n");
	ft_printf("|%4.6d", -2222222);
	printf("|\n");
	ft_printf("|% 6d", 222);
	printf("|\n");
	ft_printf("|%.0d", 0);
	printf("|\n");
}
