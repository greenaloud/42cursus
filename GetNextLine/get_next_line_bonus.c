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
	int		val;
	char	*result;
	t_list	*head;	

	if (buffer[0] == 0)
	{
		val = read(fd, buffer, BUFFER_SIZE);
		if (val <= 0)
			return (NULL);
		buffer[val] = 0;
		len = val;
	}
	else
		len = check_new_line(buffer);
	// buffer 에 유효한 값이 채워져 있는 경우에만 접근 가능한 라인
	head = read_line(fd, buffer, &len);
	// head == NULL 인 경우 -> 처리 도중 malloc 에러가 발생한 경우이므로 바로 NULL 반환: 할당을 해제하는 부분은 read_line 에서 담당
	if (head == NULL)
		return (NULL);
	// 마지막 노드의 \n 위치에 따른 len 계산이 필요
	result = malloc(sizeof *result * (len + 1));
	if (result == NULL)
		return (NULL);
	make_string(head, result, buffer);
	return result;
}

// 재귀함수! 마지막 \n 이 나오는 경우이거나 eof 를 만나서 더이상 읽을 값이 없는 경우 자동 종료
// 해당 함수에 접근 한 경우에는 buffer 에 무조건 유효한 값이 있음을 보장받음
t_list	*read_line(int fd, char *buffer, int *len)
{
	int		val;
	t_list	*new;

	new = lst_new(buffer);
	if (new == NULL)
		return (NULL);
	// nl 이 없는 경우
	if (check_new_line(buffer) == 0)
	{
		// read 의 리턴값으로 앞으로 더 읽을 수 있는 문자열이 있는지 확인
		val = read(fd, buffer, BUFFER_SIZE);
		// read 에러 처리
		if (val < 0)
			return (NULL);
		// 마지막 까지 다 읽은 경우
		else if (val == 0)
			//buffer 의 공간을 해재하는 로직이 필요하다
			return new;
		// 읽을 값이 남아있는 경우
		else
		{
			// 읽어온 값 만큼을 길이에 추가하지만 만약 마지막 버퍼이고 해당 버퍼 내부에 nl이 마지막이 아니라면 딱 맞아 떨어지지 않는다. --> make_string 에 위임?
			*len += val;
			new->next = read_line(fd, buffer, len);
			if (new->next == NULL)
				// 해당 노드를 free 하는 로직이 필요하다.
				return (NULL);
		}
	}
	// nl이 있지만 파일의 마지막이 nl 인 경우 버퍼의 메모리 해제를 어떻게 할것인지.. 그냥 무조건 nl 뒤에 있는 문자열이 있다면 buffer 에 저장하고 아니면 buffer 의 할당 해제? --> make_string에 위임해야할 듯
	return new;
}

void	make_string(t_list *node, char *result, char *buffer)
{
	int		pos;
	t_list	*del;

	(void)buffer;
	while (node->next != NULL)
	{
		result += copy_string(result, node->content, ' ');
		del = node;
		node = node->next;
		free(del);
	}
	// 현재 node 가 마지막 노드일 때 접근하게 되는 코드 -> pos 는 첫 nl 까지 포함하는 문자열의 길이
	pos = check_new_line(node->content);
	// 마지막 노드에 nl 이 없는 경우 -> eof 를 만난경우 이므로 널문자 까지 복사하면 된다. + buffer free 처리를 할 수 있는 위치! 다른부분의 라인이 부족한 경우 여기서 해제.
	if(pos == 0)
		result += copy_string(result, node->content, ' ');
	// 마지막 노드에 nl 이 있는 경우 -> \n 까지만 저장하고 나머지는 buffer에 다시 덮어쓰고 nul-terminating 을 하는 로직을 호출
	else
		result += copy_string(result, node->content, '\n');
	free(node);
}

int	copy_string(char *dst, char *src, char c)
{
	int	idx;

	idx = 0;
	while (src[idx] != c)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return idx;
}