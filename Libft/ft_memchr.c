/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:53:42 by wocho             #+#    #+#             */
/*   Updated: 2021/11/15 10:56:50 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	if (!s)
		return (0);
	str = (const unsigned char *)s;
	while (n--)
	{
		if (str[n] == c)
			return ((void *)ptr);
		ptr++;
	}
	return (0);
}
