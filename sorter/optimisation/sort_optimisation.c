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

static int	manual_sort_a_to_b(t_state *state, int depth)
{
	if (depth <= 1)
		return (CODE_OK);
	if (depth == 2)
		return (sort_a_2x(state));
	if (depth == 3)
	{
		if (state->a->size == 3 && state->b->size == 0)
			return (sort_a_3x(state, 1));
		return (sort_a_3x(state, 0));
	}
	return (CODE_ERROR_INVALID_VALUE);
}

static int	manual_sort_b_to_a(t_state *state, int depth)
{
	if (depth == 0)
		return (CODE_OK);
	if (depth == 1)
		return (pa(state, 1));
	if (depth == 2)
		return (sort_b_2x(state));
	if (depth == 3)
	{
		if (state->b->size == 3 && state->a->size == 0)
			return (sort_b_3x(state, 1));
		return (sort_b_3x(state, 0));
	}
	return (CODE_ERROR_INVALID_VALUE);
}

int	dispatch_a_to_b_clean(t_state *state, t_chunksize *chunksize)
{
	int	res;
	int	chunk_i;

	chunk_i = dispatch_by_chunk(chunksize, state->a);
	if (chunk_i == 0)
	{
		res = pb(state, 1);
		if (res < 0)
			return (res);
		if (state->b->size > 1)
			return (rb(state, 1));
	}
	else if (chunk_i == 1)
		return (pb(state, 1));
	else if (chunk_i == 2)
	{
		if (state->a->size > 1)
			return (ra(state, 1));
	}
	else
		return (CODE_ERROR_INVALID_VALUE);
	return (CODE_OK);
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
