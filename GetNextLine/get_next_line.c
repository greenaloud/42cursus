/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:37 by wocho             #+#    #+#             */
/*   Updated: 2021/12/16 21:28:31 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 1024
#define MAX_FD_COUNT 256

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD_COUNT];
	char		*result;
	int			idx;

	if (buff[fd] == NULL)
	{
		buff[fd] = malloc(sizeof (*buff[fd]) * (BUFFER_SIZE + 1));
		if (buff[fd] == NULL)
			return (NULL);
		idx = 0;
		while (idx < BUFFER_SIZE + 1)
			buff[fd][idx++] = 0;
	}
	result = get_single_line(fd, buff[fd]);
	return (result);
}

char	*get_single_line(int fd, char *buffer)
{
	int		len;
	char	*result;
	t_list	*head;	

	if (buffer[0] == 0)
	{
		int val = read(fd, buffer, BUFFER_SIZE);
		if (val <= 0)
			return (NULL);
		buffer[val] = 0;
	}
	// buffer 에 유효한 값이 채워져 있는 경우에만 접근 가능한 라인
	len = 0;
	head = read_line(fd, buffer, &len);
	// head == NULL 인 경우 -> 처리 도중 malloc 에러가 발생한 경우이므로 바로 NULL 반환: 할당을 해제하는 부분은 read_line 에서 담당
	if (head == NULL)
		return (NULL);
	result = malloc(sizeof *result * (len + 1));
	if (result == NULL)
		return (NULL);
	make_string(head, result, buffer);
	return result;
}

// 재귀함수! 마지막 \n 이 나오는 경우이거나 eof 를 만나서 더이상 읽을 값이 없는 경우 자동 종료
t_list	*read_line(int fd, char *buffer, int *len)
{
	int		pos;
	int		val;
	t_list	*new;

	pos = check_new_line(buffer);
	new = lst_new(buffer);
	if (new == NULL)
		return (NULL);
	if (pos == 0)
	{
		val = read(fd, buffer, BUFFER_SIZE);
		if (val < 0)
			return (NULL);
		// 마지막 까지 다 읽은 경우
		else if (val == 0)
			// 구현해야 할 함수 - 버퍼의 내부를 0으로 초기화
			fill_zero(buffer);
		// 읽을 값이 남아있는 경우
		else
		{
			new->next = read_line(fd, buffer, val);
			if (new->next == NULL)
				return (NULL);
		}
	}
	return new;
}

void	make_string(t_list *node, char *result, char *buffer)
{
	int		idx;
	int		pos;
	t_list	*del;

	while (node->next != NULL)
	{
		result += copy_string(result, node->content, BUFFER_SIZE);
		del = node;
		node = node->next;
		free(del);
	}
	pos = check_new_line(node->content);
	if(!pos)
		result = copy_string(result, node->content, BUFFER_SIZE);
	else
		result = copy_string(result, node->content, pos);
	*result = 0;
	free(node);
}

int	copy_string(char *dst, char *src, int len)
{
	int	idx;

	idx = 0;
	while (idx < len && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	return idx;
}
