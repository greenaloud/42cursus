/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:04:48 by wocho             #+#    #+#             */
/*   Updated: 2021/11/16 21:39:54 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		flag;
	size_t	hidx;
	size_t	nidx;

	hidx = 0;
	while (haystack[hidx])
	{
		flag = 1;
		nidx = 0;
		while (needle[nidx])
		{
			if (hidx + nidx >= len)
				return (0);
			if (haystack[hidx + nidx] != needle[nidx])
			{
				flag = 0;
				break ;
			}
			nidx++;
		}
		if (flag)
			return ((char *)(haystack + hidx));
		hidx++;
	}
	return (0);
}
