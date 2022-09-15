#include "push_swap.h"
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

int	deque_del(t_deque *this)
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
	return (CODE_OK);
}

int	deque_push_head(t_deque *this, t_node *node)
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
	return (CODE_OK);
}

int	deque_push_tail(t_deque *this, t_node *node)
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
