/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:38:00 by wocho             #+#    #+#             */
/*   Updated: 2021/12/22 10:33:30 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef MAX_OPEN
#  define MAX_OPEN 256
# endif

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;
char	*get_next_line(int fd);
t_list	*read_single_line(int fd, char **buffer, int *len);
char	*make_string(t_list *node, char *buffer, int len);
void	*free_ptr(void **ptr);
int		get_length(char *str);
int		check_nl(char *str);
int		copy_content(char *dst, char *src);
void	copy_last_content(char *dst, char *src, char *buffer);
t_list	*lst_new(char *str);
#endif
