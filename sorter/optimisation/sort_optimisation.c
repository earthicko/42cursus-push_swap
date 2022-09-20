/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimisation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:27:32 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:34 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	is_stack_sorted(t_deque *stack, int order)
{
	t_node	*cursor_prev;
	t_node	*cursor;

	if (order != SORT_ASC && order != SORT_DSC)
		return (CODE_ERROR_INVALID_VALUE);
	if (stack->size <= 1)
		return (1);
	cursor_prev = stack->head;
	cursor = stack->head->next;
	while (cursor != NULL)
	{
		if (order == SORT_ASC && cursor_prev->idx > cursor->idx)
			return (0);
		else if (order == SORT_DSC && cursor_prev->idx < cursor->idx)
			return (0);
		cursor = cursor->next;
		cursor_prev = cursor_prev->next;
	}
	return (1);
}

int	is_stack_optimisable(t_state *state, t_deque *stack, int depth)
{
	if (depth <= 3)
		return (CODE_STACK_SMALL_ENOUGH);
	else if (state->a == stack)
	{
		if (is_stack_sorted(stack, SORT_ASC))
			return (CODE_STACK_SORTED);
		else
			return (CODE_STACK_NOT_OPTIMISABLE);
	}
	else if (state->b == stack)
	{
		if (is_stack_sorted(stack, SORT_DSC))
			return (CODE_STACK_SORTED);
		else
			return (CODE_STACK_NOT_OPTIMISABLE);
	}
	else
		return (CODE_ERROR_INVALID_VALUE);
}

int	sort_optimally(t_state *state, t_deque *stack, int code, int depth)
{
	if (state->a == stack)
	{
		if (code == CODE_STACK_SORTED)
			return (CODE_OK);
		else if (code == CODE_STACK_SMALL_ENOUGH)
			return (manual_sort_a_to_b(state, depth));
	}
	else if (state->b == stack)
	{
		if (code == CODE_STACK_SORTED)
			return (do_n_times(state, pa, depth, 1));
		else if (code == CODE_STACK_SMALL_ENOUGH)
			return (manual_sort_b_to_a(state, depth));
	}
	return (CODE_ERROR_INVALID_VALUE);
}
