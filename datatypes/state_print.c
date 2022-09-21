/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:15 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "state.h"

static void	print_op_name(int i_op)
{
	if (i_op == SA)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (i_op == SB)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (i_op == SS)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (i_op == PA)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (i_op == PB)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (i_op == RA)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (i_op == RB)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (i_op == RR)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (i_op == RRA)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (i_op == RRB)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (i_op == RRR)
		ft_putendl_fd("rrr", STDOUT_FILENO);
}

void	state_print_op_queue(t_state *state)
{
	t_node	*node;

	while (state->print_queue->size > 0)
	{
		node = deque_pop_head(state->print_queue);
		print_op_name(node->idx);
		free(node);
	}
}
