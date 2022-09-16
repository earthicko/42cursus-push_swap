#include "t_deque.h"

t_node	*node_init(int idx)
{
	t_node	*init;

	init = (t_node *)malloc(sizeof(t_node));
	if (!init)
		return (NULL);
	init->prev = NULL;
	init->next = NULL;
	init->idx = idx;
	return (init);
}

t_deque	*deque_init(void)
{
	t_deque	*init;

	init = (t_deque *)malloc(sizeof(t_deque));
	if (!init)
		return (NULL);
	init->head = NULL;
	init->tail = NULL;
	init->size = 0;
	return (init);
}

void	deque_del(t_deque *this)
{
	t_node	*cursor;
	t_node	*cursor_next;

	cursor = this->head;
	while (cursor)
	{
		cursor_next = cursor->next;
		free(cursor);
		cursor = cursor_next;
	}
	free(this);
}
