/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:28:13 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:15 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "deque_debug.h"

void	print_deque_node_line(t_deque *this, void f_print(t_node *))
{
	t_node	*cursor;

	cursor = this->head;
	while (cursor)
	{
		f_print(cursor);
		printf(" ");
		cursor = cursor->next;
	}
	printf("\n");
}

void	print_deque(t_deque *this)
{
	printf("[ deque size %.3d ]\n", this->size);
	printf("   head: [%.3lx]    \n", (size_t)this->head % 0x100);
	printf("   tail: [%.3lx]    \n", (size_t)this->tail % 0x100);
	print_deque_node_line(this, print_node_title);
	print_deque_node_line(this, print_node_prev);
	print_deque_node_line(this, print_node_next);
	print_deque_node_line(this, print_node_idx);
}
