/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:36:54 by wocho             #+#    #+#             */
/*   Updated: 2022/01/11 19:36:10 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_func[7] = {
	print_char,
	print_integer,
	print_unsigned,
	print_pointer,
	print_hexa,
	print_string,
	print_sign
};

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
			s = print_param(s, ap, &count);
		else
			s += print_string(s, &count);
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

	init_set(&sett);
	s = get_setting(s, &sett);
	s = get_width(s, &sett);
	s = get_precision(s, &sett);
	*count += func_list[type](ap, sett, count);
	return (s);
}
