/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:08 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:09 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
# include "codes.h"

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
int		deque_push_tail_idx(t_deque *this, int idx);
t_node	*deque_pop_head(t_deque *deque);
t_node	*deque_pop_tail(t_deque *deque);

#endif
