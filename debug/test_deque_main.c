/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_deque_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:28:19 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:20 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"
#include <stdio.h>
#include "deque_debug.h"

void	test_push_head(t_deque *deque, int idx)
{
	t_node	*node;

	node = node_init(idx);
	deque_push_head(deque, node);
	printf("After push_head %d:\n", idx);
	print_deque(deque);
}

void	test_push_tail(t_deque *deque, int idx)
{
	t_node	*node;

	node = node_init(idx);
	deque_push_tail(deque, node);
	printf("After push_tail %d:\n", idx);
	print_deque(deque);
}

void	test_pop_head(t_deque *deque)
{
	t_node	*popped;

	popped = deque_pop_head(deque);
	printf("After pop_head %d:\n", popped->idx);
	print_deque(deque);
	free(popped);
}

void	test_pop_tail(t_deque *deque)
{
	t_node	*popped;

	popped = deque_pop_tail(deque);
	printf("After pop_tail %d:\n", popped->idx);
	print_deque(deque);
	free(popped);
}

int	main(void)
{
	t_deque	*deque;
	t_node	*node;

	deque = deque_init();
	printf("After init:\n");
	print_deque(deque);
	test_push_head(deque, 0);
	test_push_head(deque, 1);
	test_push_head(deque, 2);
	test_push_head(deque, 3);
	test_pop_tail(deque);
	test_pop_head(deque);
	test_pop_tail(deque);
	test_pop_tail(deque);
	test_pop_tail(deque);
	test_push_tail(deque, 7);
	test_push_head(deque, 4);
	test_pop_head(deque);
	test_push_tail(deque, 8);
	test_pop_tail(deque);
	test_push_tail(deque, 5);
	test_pop_tail(deque);
	test_pop_tail(deque);
	test_pop_tail(deque);
	return (0);
}
