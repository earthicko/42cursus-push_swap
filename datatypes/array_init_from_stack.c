/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_init_from_stack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:50:47 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/20 16:50:49 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datatype_conversion.h"

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
