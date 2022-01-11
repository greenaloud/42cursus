/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:04:08 by wocho             #+#    #+#             */
/*   Updated: 2022/01/11 17:44:43 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# define FLAG_ZERO		1
# define FLAG_LEFT		2
# define FLAG_PLUS		4
# define FLAG_SPACE		8
# define FLAG_HASH		16
# define FLAG_UPPER		32
# define FLAG_PRECISION	64

typedef struct s_sett
{
	int	flag;
	int	width;
	int	precision;
}			t_sett
typedef	int	(*t_func)(va_list, t_sett, int *);
#endif
