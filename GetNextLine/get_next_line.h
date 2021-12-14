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
	char			content[BUFFER_SIZE];
	struct s_list	*next;
}				t_list;
char	*get_next_line(int fd);
int	check_new_line(char *str, int len);
void	copy_str(char *copy, char *buff);
t_list	*add_new(t_list *cur, char *buff);
#endif