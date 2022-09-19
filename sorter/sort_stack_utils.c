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

#include "sorter.h"
#include "libft.h"
#include "array.h"
#include "utils.h"

t_array	*array_init_from_stack(t_deque *stack, int depth)
{
	t_array	*init;
	t_node	*node;

	if (depth > stack->size)
		return (NULL);
	init = array_init(depth);
	if (!init)
		return (NULL);
	node = stack->head;
	while (depth--)
	{
		array_append(init, node->idx);
		node = node->next;
	}
	return (init);
}

int	analyse_chunk(t_chunksize *size, t_deque *stack, int depth)
{
	t_array	*sorted_idx;

	ft_memset(size->size, 0, sizeof(size->size));
	sorted_idx = array_init_from_stack(stack, depth);
	if (!sorted_idx)
		return (CODE_ERROR_MALLOC);
	ft_sort_int_tab(sorted_idx->data, depth);
	size->div[0] = sorted_idx->data[0];
	size->div[1] = sorted_idx->data[depth / 3];
	size->div[2] = sorted_idx->data[depth * 2 / 3];
	size->div[3] = sorted_idx->data[depth - 1];
	array_del(sorted_idx);
	return (CODE_OK);
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
