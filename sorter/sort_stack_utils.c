/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:53 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:54 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "sorter.h"
#include "libft.h"

void	analyse_chunk(t_chunksize *size, t_deque *stack, int depth)
{
	int		i;
	t_node	*node;

	size->div[0] = INT_MAX;
	size->div[3] = INT_MIN;
	ft_memset(size->size, 0, sizeof(size->size));
	node = stack->head;
	i = 0;
	while (i < depth)
	{
		if (node->idx < size->div[0])
			size->div[0] = node->idx;
		if (node->idx > size->div[3])
			size->div[3] = node->idx;
		node = node->next;
		i++;
	}
	size->div[1] = size->div[0] + (size->div[3] - size->div[0]) / 3;
	size->div[2] = size->div[0] + 2 * (size->div[3] - size->div[0]) / 3;
}

int	dispatch_by_chunk(t_chunksize *chunksize, t_deque *stack)
{
	int	idx;
	int	chunk_i;

	idx = stack->head->idx;
	if (chunksize->div[0] <= idx && idx < chunksize->div[1])
		chunk_i = 0;
	else if (chunksize->div[1] <= idx && idx < chunksize->div[2])
		chunk_i = 1;
	else if (chunksize->div[2] <= idx && idx <= chunksize->div[3])
		chunk_i = 2;
	else
		return (CODE_ERROR_INVALID_VALUE);
	chunksize->size[chunk_i]++;
	return (chunk_i);
}

int	is_stack_sorted(t_deque *stack, int order)
{
	t_node	*cursor_prev;
	t_node	*cursor;

	if (order != SORT_ASC && order != SORT_DSC)
		return (CODE_ERROR_INVALID_VALUE);
	if (stack->size <= 1)
		return (1);
	cursor_prev = stack->head;
	cursor = stack->head->next;
	while (cursor != NULL)
	{
		if (order == SORT_ASC && cursor_prev->idx > cursor->idx)
			return (0);
		else if (order == SORT_DSC && cursor_prev->idx < cursor->idx)
			return (0);
		cursor = cursor->next;
		cursor_prev = cursor_prev->next;
	}
	return (1);
}
