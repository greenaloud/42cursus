/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:04:08 by wocho             #+#    #+#             */
/*   Updated: 2022/01/12 18:24:45 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
// 제출 전 꼭 삭제할 것
# include <stdio.h>
// 제출 전 꼭 삭제할 것
# define FLAG_ZERO		1
# define FLAG_LEFT		2
# define FLAG_PLUS		4
# define FLAG_SPACE		8
# define FLAG_HASH		16
# define FLAG_UPPER		32
# define FLAG_PRECISION	64
# define FLAG_COMB		128

typedef struct s_sett
{
	int	flag;
	int	width;
	int	precision;
}			t_sett;

char	*get_setting(char *s, t_sett *sett);
char	*get_width(char *s, t_sett *sett);
char	*get_precision(char *s, t_sett *sett);
int		ft_printf(const char *s, ...);
int		print_string(char *s, int *count);
char	*print_param(char *s, va_list ap, int *count);
int		ft_atoi(char **s_ptr);
char	*ft_itoa(int n, int min, t_sett *sett, int *count);
int		print_int(va_list ap, t_sett *sett);
void	init_sett(t_sett *sett);
void	complete_flag(t_sett *sett);
void	left_justify(char *str, int len);
int		get_type(char *s);
int		print_char(va_list ap, t_sett *sett);
int		print_str(va_list ap, t_sett *sett);
#endif
