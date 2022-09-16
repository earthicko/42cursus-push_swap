#ifndef T_DEQUE_H
# define T_DEQUE_H
# include <stdlib.h>
# include "consts.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				idx;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_deque;

t_node	*node_init(int idx);
t_deque	*deque_init(void);
void	deque_del(t_deque *deque);
void	deque_push_head(t_deque *deque, t_node *node);
void	deque_push_tail(t_deque *deque, t_node *node);
t_node	*deque_pop_head(t_deque *deque);
t_node	*deque_pop_tail(t_deque *deque);

#endif
