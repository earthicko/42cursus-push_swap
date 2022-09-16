#include "deque.h"
#include <stdio.h>
#include "deque_debug.h"

int	main(void)
{
	t_deque	*deque;
	t_node	*node;

	deque = deque_init();

	printf("After init:\n");
	print_deque(deque);
	
	node = node_init(0);
	deque_push_head(deque, node);
	printf("After push 0:\n");
	print_deque(deque);

	node = node_init(1);
	deque_push_head(deque, node);
	printf("After push 1:\n");
	print_deque(deque);

	node = node_init(2);
	deque_push_head(deque, node);
	printf("After push 2:\n");
	print_deque(deque);

	node = node_init(3);
	deque_push_head(deque, node);
	printf("After push 3:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);

	deque_pop_head(deque);
	printf("After pop_head:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);

	node = node_init(7);
	deque_push_tail(deque, node);
	printf("After push 7:\n");
	print_deque(deque);

	node = node_init(4);
	deque_push_head(deque, node);
	printf("After push 4:\n");
	print_deque(deque);

	deque_pop_head(deque);
	printf("After pop_head:\n");
	print_deque(deque);

	node = node_init(8);
	deque_push_tail(deque, node);
	printf("After push 8:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);

	node = node_init(5);
	deque_push_tail(deque, node);
	printf("After push 5:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);

	deque_pop_tail(deque);
	printf("After pop_tail:\n");
	print_deque(deque);
	
	return 0;
}