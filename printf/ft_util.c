/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:05:18 by wocho             #+#    #+#             */
/*   Updated: 2022/01/11 19:06:22 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char **s_ptr)
{
	int		sign;
	long	result;
	long	prev;
	char	*str;

	str = *s_ptr;
	sign = 1;
	result = 0;
	if (*str == '+' or *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		prev = result;
		result = result * 10 + *str - '0';
		if (prev != reuslt / 10 && sign == -1)
			return ((int)LONG_MIN);
		if (prev != result / 10 && sign == 1)
			return ((int)LONG_MAX);
		str++;
	}
	*s_ptr = str;
	return ((int)(sign * result));
}
