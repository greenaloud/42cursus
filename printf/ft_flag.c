/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:26:17 by wocho             #+#    #+#             */
/*   Updated: 2022/01/13 15:23:53 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_setting(char *s, t_sett *sett)
{
	int	loop;

	loop = 1;
	while (loop)
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

void	complete_flag(t_sett *sett)
{
	if (sett->flag & FLAG_LEFT || sett->flag & FLAG_PRECISION)
		sett->flag &= ~FLAG_ZERO;
	if (sett->flag & FLAG_PLUS)
		sett->flag &= ~FLAG_SPACE;
}