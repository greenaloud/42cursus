/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:14:30 by wocho             #+#    #+#             */
/*   Updated: 2021/11/18 10:26:22 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;

	if (start >= ft_strlen(s))
	{
		result = malloc(sizeof (*result));
		result[0] = 0;
		return (result);
	}
	result = malloc(sizeof (*result) * (len + 1));
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (s[idx] && idx < len)
	{
		result[idx] = s[start + idx];
		idx++;
	}
	result[idx] = 0;
	return (result);
}
