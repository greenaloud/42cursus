/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 04:27:01 by wocho             #+#    #+#             */
/*   Updated: 2021/11/30 17:45:44 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_count(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		while (s[idx] == c)
			idx++;
		if (s[idx])
			cnt++;
		while (s[idx] != 0 && s[idx] != c)
			idx++;
	}
	return (cnt);
}

static char	*process(char const *s, int *lt, int rt)
{
	int		idx;
	char	*str;

	str = malloc(sizeof (*str) * (rt - *lt + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (*lt < rt)
	{
		str[idx] = s[*lt];
		(*lt)++;
		idx++;
	}
	str[idx] = 0;
	return (str);
}

static void	divide(char **arr, char const *s, char c)
{
	int	lt;
	int	rt;
	int	idx;

	lt = 0;
	rt = 0;
	idx = 0;
	while (s[rt])
	{
		if (s[rt] != c)
			rt++;
		else
		{
			if (lt == rt)
			{
				lt++;
				rt++;
			}
			else
				arr[idx++] = process(s, &lt, rt);
		}
	}
	if (lt != rt)
		arr[idx++] = process(s, &lt, rt);
	arr[idx] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**result;

	cnt = get_count(s, c);
	result = malloc(sizeof (*result) * (cnt + 1));
	if (result == NULL)
		return (NULL);
	divide(result, s, c);
	return (result);
}
