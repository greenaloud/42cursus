/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:49 by wocho             #+#    #+#             */
/*   Updated: 2021/12/14 17:56:08 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 256


int	check_new_line(char *str, int len)
{
	int	idx;

	idx = 0;
	while (idx < len)
	{
		if (str[idx] == '\n')
			return (1);
		idx++;
	}
	return (0);
}

void	copy_str(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (idx < BUFFER_SIZE)
	{
		dest[idx] = src[idx];
		idx++;
	}
}