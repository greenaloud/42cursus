/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:48:38 by wocho             #+#    #+#             */
/*   Updated: 2021/11/13 16:47:30 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			idx;
	unsigned char	fill;

	if (!b)
		return (0);
	fill = (unsigned char)c;
	idx = 0;
	while (idx < len)
	{
		*((unsigned char *)b + idx) = fill;
		idx++;
	}
	return (b);
}
