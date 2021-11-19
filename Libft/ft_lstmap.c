/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:30:27 by wocho             #+#    #+#             */
/*   Updated: 2021/11/19 21:52:34 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*temp;
	t_list	*delnode;

	delnode = lst;
	temp = malloc(sizeof (*temp));
	if (temp == NULL)
		return (NULL);
	newlst = temp;
	temp->content = f(lst->content);
	del(lst->content);
	temp->next = lst->next;
	free(delnode);
	while (lst != NULL)
	{
		delnode = lst;
		temp = malloc(sizeof (*temp));
		if (temp == NULL)
			return (NULL);
		temp->content = f(lst->content);
		del(lst->content);
		temp->next = lst->next;
		lst = lst->next;
		free(delnode);
	}
	return (newlst);
}
