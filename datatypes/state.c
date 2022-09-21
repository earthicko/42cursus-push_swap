/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:15 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "datatype_conversion.h"

t_state	*state_init(t_array *arr)
{
	t_state	*init;

	init = (t_state *)malloc(sizeof(t_state));
	if (!init)
		return (NULL);
	ft_memset(init, 0, sizeof(t_state));
	init->a = stack_init_from_array(arr);
	init->b = deque_init();
	init->print_queue = deque_init();
	if (!init->a || !init->b || !init->print_queue)
	{
		state_del(init);
		return (NULL);
	}
	return (init);
}

void	state_del(t_state *state)
{
	if (state->a)
		deque_del(state->a);
	if (state->b)
		deque_del(state->b);
	if (state->print_queue)
		deque_del(state->print_queue);
	free(state);
}

static void	merge_operations_if_possible(t_node *node)
{
	t_node	*next;
	int		i;
	int		j;

	next = node->next;
	if (!next)
		return ;
	i = node->idx;
	j = next->idx;
	if ((i == SA && j == SB) || (i == SB && j == SA))
	{
		node->idx = SS;
		next->idx = NONE;
	}
	else if ((i == RA && j == RB) || (i == RB && j == RA))
	{
		node->idx = RR;
		next->idx = NONE;
	}
	else if ((i == RRA && j == RRB) || (i == RRB && j == RRA))
	{
		node->idx = RRR;
		next->idx = NONE;
	}
}

void	merge_operations(t_state *state)
{
	t_node	*node;

	node = state->print_queue->head;
	while (node)
	{
		merge_operations_if_possible(node);
		node = node->next;
	}
}

int	do_n_times(t_state *state, int f(t_state *), int n)
{
	int	res;
	int	i;

	i = 0;
	while (i < n)
	{
		res = f(state);
		if (res < 0)
			return (res);
		i++;
	}
	return (CODE_OK);
}
