/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:06 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:08 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	deque_push_head(t_deque *this, t_node *node)
{
	t_node	*head_prev;

	head_prev = this->head;
	this->head = node;
	node->prev = NULL;
	node->next = head_prev;
	if (this->size == 0)
		this->tail = node;
	else
		head_prev->prev = node;
	this->size++;
}

void	deque_push_tail(t_deque *this, t_node *node)
{
	t_node	*tail_prev;

	tail_prev = this->tail;
	this->tail = node;
	node->next = NULL;
	node->prev = tail_prev;
	if (this->size == 0)
		this->head = node;
	else
		tail_prev->next = node;
	this->size++;
}

int	deque_push_tail_idx(t_deque *this, int idx)
{
	t_node	*node;

	node = node_init(idx);
	if (!node)
		return (CODE_ERROR_MALLOC);
	deque_push_tail(this, node);
	return (CODE_OK);
}

t_node	*deque_pop_head(t_deque *this)
{
	t_node	*head;
	t_node	*head_next;

	if (this->size <= 0)
		return (NULL);
	head = this->head;
	head_next = this->head->next;
	if (this->size == 1)
	{
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		this->head = head_next;
		this->head->prev = NULL;
	}
	this->size--;
	return (head);
}

t_node	*deque_pop_tail(t_deque *this)
{
	t_node	*tail;
	t_node	*tail_prev;

	if (this->size <= 0)
		return (NULL);
	tail = this->tail;
	tail_prev = this->tail->prev;
	if (this->size == 1)
	{
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		this->tail = tail_prev;
		this->tail->next = NULL;
	}
	this->size--;
	return (tail);
}
