/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_from_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:32 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:33 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatype_conversion.h"

static int	push_node_if_valid(t_deque *stack, t_array *arr, int idx_arr)
{
	t_node	*node;
	int		idx;
	int		i;

	idx = 0;
	i = 0;
	while (i < arr->len)
	{
		if (i != idx_arr && arr->data[i] == arr->data[idx_arr])
			return (CODE_ERROR_INVALID_VALUE);
		if (arr->data[i] < arr->data[idx_arr])
			idx++;
		i++;
	}
	node = node_init(idx);
	if (!node)
		return (CODE_ERROR_MALLOC);
	deque_push_tail(stack, node);
	return (CODE_OK);
}

t_deque	*stack_init_from_array(t_array *arr)
{
	t_deque	*stack;
	int		i;
	int		res;

	stack = deque_init();
	if (!stack)
		return (NULL);
	i = 0;
	while (i < arr->len)
	{
		res = push_node_if_valid(stack, arr, i);
		if (res < 0)
		{
			deque_del(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
