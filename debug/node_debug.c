/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:28:15 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "deque.h"

void	print_node_title(t_node *node)
{
	printf("=== node [%.3lx] ===>", (size_t)node % 0x100);
}

void	print_node_prev(t_node *node)
{
	printf("   prev: [");
	if (node->prev)
		printf("%.3lx", (size_t)node->prev % 0x100);
	else
		printf("---");
	printf("]     ");
}

void	print_node_next(t_node *node)
{
	printf("   next: [");
	if (node->next)
		printf("%.3lx", (size_t)node->next % 0x100);
	else
		printf("---");
	printf("]     ");
}

void	print_node_idx(t_node *node)
{
	printf("   idx:   %3d      ", node->idx);
}

void	print_node(t_node *node)
{
	print_node_title(node);
	printf("\n");
	print_node_prev(node);
	printf("\n");
	print_node_next(node);
	printf("\n");
	print_node_idx(node);
	printf("\n");
}
