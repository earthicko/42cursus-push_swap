#ifndef STACK_H
# define STACK_H
# include "t_deque.h"

int	stack_swap(t_deque *this);
int	stack_push(t_deque *from, t_deque *to);
int	stack_rotate(t_deque *this);
int	stack_rev_rotate(t_deque *this);
#endif
