/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:09 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:11 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_swap(t_deque *this)
{
	t_node	*node0;
	t_node	*node1;

	if (this->size < 2)
		return (CODE_ERROR_STACK_TOO_SMALL);
	node0 = deque_pop_head(this);
	node1 = deque_pop_head(this);
	deque_push_head(this, node0);
	deque_push_head(this, node1);
	return (CODE_OK);
}

int	stack_push(t_deque *from, t_deque *to)
{
	t_node	*node;

	if (from->size < 1)
		return (CODE_ERROR_STACK_TOO_SMALL);
	node = deque_pop_head(from);
	deque_push_head(to, node);
	return (CODE_OK);
}

int	stack_rotate(t_deque *this)
{
	t_node	*node;

	if (this->size < 2)
		return (CODE_ERROR_STACK_TOO_SMALL);
	node = deque_pop_head(this);
	deque_push_tail(this, node);
	return (CODE_OK);
}

int	stack_rev_rotate(t_deque *this)
{
	t_node	*node;

	if (this->size < 2)
		return (CODE_ERROR_STACK_TOO_SMALL);
	node = deque_pop_tail(this);
	deque_push_head(this, node);
	return (CODE_OK);
}
