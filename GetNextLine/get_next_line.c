/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:37:37 by wocho             #+#    #+#             */
/*   Updated: 2021/12/09 21:01:59 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buff;
	int		value;
	int		flag;
	
	buff = malloc(sizeof *buff * (BUFFER_SIZE));
	if (buff == NULL)
		return (NULL);
	flag = 1;
	while (flag)
	{
		value = read(fd, buff, BUFFER_SIZE);
		while (value-- > 0) {

		flag = check_new_line(buff);
			
}
