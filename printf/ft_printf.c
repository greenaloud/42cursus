/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:36:54 by wocho             #+#    #+#             */
/*   Updated: 2022/01/14 16:44:30 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_string(char *s, int *count)
{
	int	idx;
	int	ret;

	idx = 0;
	while (s[idx] && s[idx] != '%')
		idx++;
	ret = write(1, s, idx);
	if (ret < 0)
		*count = ret;
	else
		*count += ret;
	return (idx);
}

static int	get_type(char *s, t_sett *sett)
{
	if (*s == 'd' || *s == 'i')
		return (0);
	else if (*s == 'u')
		return (1);
	else if (*s == 'x' || *s == 'X')
	{
		if (*s == 'X')
			sett->flag |= FLAG_UPPER;
		return (2);
	}
	else if (*s == 'p')
		return (3);
	else if (*s == 'c')
		return (4);
	else if (*s == 's')
		return (5);
	else if (*s == '%')
		return (6);
	return (-1);
}

static char	*print_param(char *s, va_list ap, int *count)
{
	int			ret;
	t_sett		sett;
	static int	(*func_list[7])(va_list, t_sett *) = {print_int, print_u_int,
		print_hex, print_addr, print_char, print_str, print_percent};

	s = get_setting(++s, &sett);
	ret = func_list[get_type(s, &sett)](ap, &sett);
	if (ret < 0)
		*count = ret;
	else
		*count += ret;
	s++;
	return (s);
}

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
		if (count < 0)
			break ;
	}
	va_end(ap);
	return (count);
}
