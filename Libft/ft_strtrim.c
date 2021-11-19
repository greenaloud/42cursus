/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 02:33:26 by wocho             #+#    #+#             */
/*   Updated: 2021/11/19 04:24:49 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(set);
	if (len == 0)
		return (1);
	while (idx < len)
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (end && in_set(s1[end], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	start = get_start(s1, set);
	end = get_end(s1, set);
	if (ft_strlen(s1) == 0 || start > end)
	{
		result = malloc(sizeof (*result));
		result[0] = 0;
		return (result);
	}
	result = malloc(sizeof (*result) * (end - start + 2));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 2);
	return (result);
}
