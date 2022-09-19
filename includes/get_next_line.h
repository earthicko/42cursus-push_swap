/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:08:54 by donghyle          #+#    #+#             */
/*   Updated: 2022/08/09 18:08:55 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fdlist
{
	int				fd;
	char			*buff;
	struct s_fdlist	*next;
}	t_fdlist;

char		*get_next_line(int fd);
void		*del_list(t_fdlist **buff_list, t_fdlist *target);
t_fdlist	*init_list(t_fdlist **head, int init_fd);

#endif
