/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:04:08 by wocho             #+#    #+#             */
/*   Updated: 2022/01/14 16:43:46 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define FLAG_ZERO		1
# define FLAG_LEFT		2
# define FLAG_PLUS		4
# define FLAG_SPACE		8
# define FLAG_HASH		16
# define FLAG_UPPER		32
# define FLAG_PRECISION	64
# define FLAG_SIGN		128

typedef struct s_sett
{
	int	flag;
	int	width;
	int	precision;
}			t_sett;

int		ft_printf(const char *s, ...);
char	*get_setting(char *s, t_sett *sett);
int		print_int(va_list ap, t_sett *sett);
int		print_u_int(va_list ap, t_sett *sett);
int		print_hex(va_list ap, t_sett *sett);
int		print_addr(va_list ap, t_sett *sett);
int		print_char(va_list ap, t_sett *sett);
int		print_str(va_list ap, t_sett *sett);
int		print_percent(va_list ap, t_sett *sett);
void	fill_zero(char *result, t_sett *sett, int *last, int *len);
void	left_justify(char *str, int len);
int		write_and_return(char *result, int count);
#endif
