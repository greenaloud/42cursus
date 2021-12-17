/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:49 by wocho             #+#    #+#             */
/*   Updated: 2021/12/16 21:28:29 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_line(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\n')
			return (idx + 1);
		idx++;
	}
	return (0);
}

t_list	*lst_new(char *str)
{
	int		idx;
	t_list	*new;

	idx = 0;
	new = malloc(sizeof *new);
	while (str[idx])
	{
		(new->content)[idx] = str[idx];
		idx++;
	}
	(new->content)[idx] = 0;
	return new;
}
	
