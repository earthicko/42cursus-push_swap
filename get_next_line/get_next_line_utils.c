/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:08:47 by donghyle          #+#    #+#             */
/*   Updated: 2022/08/09 18:08:48 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fdlist	*init_list(t_fdlist **head, int init_fd)
{
	t_fdlist	*init;

	init = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (!init)
		return (NULL);
	init->fd = init_fd;
	init->buff = NULL;
	init->next = *head;
	*head = init;
	return (init);
}

void	*del_list(t_fdlist **buff_list, t_fdlist *target)
{
	t_fdlist	*cursor;
	t_fdlist	*prev;

	if (*buff_list == target)
	{
		*buff_list = target->next;
		free(target->buff);
		free(target);
		return (NULL);
	}
	cursor = (*buff_list)->next;
	prev = *buff_list;
	while (cursor != NULL)
	{
		if (cursor == target)
		{
			prev->next = cursor->next;
			free(cursor->buff);
			free(cursor);
			return (NULL);
		}
		cursor = cursor->next;
		prev = prev->next;
	}
	return (NULL);
}
