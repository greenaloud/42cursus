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
	int		idx;
	char	*result;
	t_list	**root;	

	len = 0;
	if (bufffer[0] != 0)
		// 버퍼가 0이 아니라면 노드를 생성 후 내용을 채우고 루트로 설정하고 그 다음 처리함수 호출?
		root = read_line(fd, buffer, &len);
	else
	{
		int val = read(fd, buffer, BUFFER_SIZE);
		// 지뢰 포인트
		if (val == 0)
			return (NULL);
		buffer[val] = 0;
		root = read_line(fd, buffer, &len);
	}
	if (len > 0)
	{
		result = malloc(sizeof *result * (len + 1));
		if (result == NULL)
			return (NULL);
	}
	make_string(*root, result, buffer);
	return result;
}

t_list	*read_line(int fd, char *buffer, int *len)
{
	int		pos;
	int		val;
	t_list	*new;

	pos = check_new_line(buffer);
	new = lst_new(buffer);
	// malloc 에러
	if (pos == 0)
	{
		val = read(fd, buffer, BUFFER_SIZE);
		// 지뢰 포인트 val < 0 ??
		if (val >= 0)
			new->next = read_line(fd, buffer, len);
		//buffer[val] = 0;
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
		node = node.next;
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
