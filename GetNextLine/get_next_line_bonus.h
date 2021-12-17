/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:38:00 by wocho             #+#    #+#             */
/*   Updated: 2021/12/09 20:35:45 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list {
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;
char	*get_next_line(int fd);
int	check_new_line(char *str);
t_list	*lst_new(char *str);
int	copy_string(char *dst, char *src, char c);
void	make_string(t_list *node, char *result, char *buffer);
t_list	*read_line(int fd, char *buffer, int *len);
char	*get_single_line(int fd, char *buffer);
#endif