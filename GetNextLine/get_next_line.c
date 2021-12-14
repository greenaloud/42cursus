/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:37 by wocho             #+#    #+#             */
/*   Updated: 2021/12/14 17:56:01 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*s_buff[BUFFER_SIZE];

char	*get_next_line(int fd)
{
	char	*buff[BUFFER_SIZE];
	int		len;
	int		count;
	t_list	**head;
	t_list	*cur;
	
	len = read(fd, buff, BUFFER_SIZE);
	while (len != 0)
	{
		// 만약 버퍼 내에 개행문자가 없다면 -> 파일의 끝도 개행문자이기 때문에 이 분기로 오는 buff 는 꽉 차 있음을 보장받음
		if(check_new_line(buff, len) == 0)
		{
			cur = add_new(cur, buff);
			// 할당 도중 문제가 생긴 경우 NULL 반환
			if (cur == NULL)
				return (NULL);
		}
		// 버퍼에 개행이 있는 경우
		else
			return make_string(*head, buff, len, count * BUFFER_SIZE + len);
		count++;
	}
	// 해당 라인에 온다면 fd 의 커서가 마지막까지 움직인 경우로 봐도 되는가? 확실하지 않음
	return (NULL);
}

char	*make_string(t_list **head, char *buff, int len, int size)
{
	char	*result;
	char	*temp;
	t_list	*cur;
	t_list	*del;
	int		idx;

	result = malloc(sizeof *result * size);
	temp = result;
	cur = *head;
	while (cur != NULL)
	{
		copy_str(temp, cur->content);
		del = cur;
		cur = cur->next;
		free(del);
		temp += BUFFER_SIZE;
	}
	free(head);
	idx = 0;
	while (idx < len && buff[idx] != '\n')
	{
		temp[idx] = buff[idx];
		idx++;
	}
	// 개행문자 이후의 남은 문자들을 static 변수에 저장해야 한다.
	return (result);
}

t_list	*add_new(t_list *cur, char *buff)
{
	t_list *new;

	new = malloc(sizeof *new);
	if (new == NULL)
		return (NULL);
	copy_str(new->content, buff);
	new->next = NULL;
	cur->next = new;
	return new;
}