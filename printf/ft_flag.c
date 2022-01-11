/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:26:17 by wocho             #+#    #+#             */
/*   Updated: 2022/01/11 18:14:42 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_setting(char *s, t_sett *sett)
{
	int	condition;

	condition = 1;
	while (condition)
	{
		if (*s == '0')
			sett->flag |= FLAG_ZERO;
		else if (*s == '-')
			sett->flag |= FLAG_LEFT;
		else if (*s == '+')
			sett->flag |= FLAG_PLUS;
		else if (*s == ' ')
			sett->flag |= FLAG_SPACE;
		else if (*s == '#')
			sett->flag |= FLAG_HASH;
		else
			break ;
		s++;
	}
	return (s);
}

char	*get_width(char *s, t_sett *sett)
{
	sett->width = ft_atoi(&s);
	return (s);
}

char	*get_precision(char *s, t_sett *sett)
{
	if (*s == '.')
	{
		sett->flag |= FLAG_PRECISION;
		s++;
		sett->precision = ft_atoi(&s);
	}
	return (s);
}


