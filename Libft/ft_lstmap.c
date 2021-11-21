/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:30:27 by wocho             #+#    #+#             */
/*   Updated: 2021/11/20 12:28:45 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*curnode;
	t_list	*delnode;
	t_list	*nextnode;

	first = malloc(sizeof (*first));
	curnode = first;
	curnode->next = NULL;
	while (lst->next != NULL)
	{
		curnode->content = f(lst->content);
		nextnode = malloc(sizeof (*nextnode));
		if (nextnode == NULL)
			return (NULL);
		nextnode->next = NULL;
		curnode->next = nextnode;
		curnode = curnode->next;
		delnode = lst;
		lst = lst->next;
		del(delnode->content);
		free(delnode);
	}
	curnode->content = f(lst->content);
	del(lst->content);
	free(lst);
	return (first);
}
