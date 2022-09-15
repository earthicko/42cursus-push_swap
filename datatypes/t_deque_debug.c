#include <stdio.h>
#include "t_deque.h"

void	print_node_title(t_node *node)
{
	printf("====node [%.3lx]====", (size_t)node % 0x100);
}

void	print_node_prev(t_node *node)
{
	printf("   prev: [");
	if (node->prev)
		printf("%.3lx", (size_t)node->prev % 0x100);
	else
		printf("---");
	printf("]    ");
}

void	print_node_next(t_node *node)
{
	printf("   next: [");
	if (node->next)
		printf("%.3lx", (size_t)node->next % 0x100);
	else
		printf("---");
	printf("]    ");
}

void	print_node_idx(t_node *node)
{
	printf("   idx:   %3d     ", node->idx);
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
	printf("====deque size %.3d====\n", this->size);
	printf("    head: [%.3lx]       \n", (size_t)this->head % 0x100);
	printf("    tail: [%.3lx]       \n", (size_t)this->tail % 0x100);
	print_deque_node_line(this, print_node_title);
	print_deque_node_line(this, print_node_prev);
	print_deque_node_line(this, print_node_next);
	print_deque_node_line(this, print_node_idx);
}
