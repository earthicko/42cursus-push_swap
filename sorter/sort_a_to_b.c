/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:49 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:50 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	manual_sort_a_to_b(t_state *state, int depth)
{
	if (depth <= 1)
		return (CODE_OK);
	if (depth == 2)
		return (sort_a_2x(state));
	if (depth == 3 && state->a->size == 3)
		return (sort_a_3x(state, 1));
	if (depth == 3 && state->a->size != 3)
		return (sort_a_3x(state, 0));
	return (CODE_ERROR_INVALID_VALUE);
}

int	rev_rotate_a_to_b(t_state *state, t_chunksize *chunksize)
{
	int	n_rra;
	int	n_rrb;
	int	n_rrr;
	int	res;

	n_rra = chunksize->size[2];
	n_rrb = chunksize->size[1];
	if (state->a->size < 2)
		n_rra = 0;
	if (state->b->size < 2)
		n_rrb = 0;
	if (n_rra < n_rrb)
		n_rrr = n_rra;
	else
		n_rrr = n_rrb;
	res = do_n_times(state, rrr, n_rrr);
	if (res < 0)
		return (res);
	res = do_n_times(state, rrb, n_rrb - n_rrr);
	if (res < 0)
		return (res);
	res = do_n_times(state, rra, n_rra - n_rrr);
	return (res);
}

int	dispatch_a_to_b(t_state *state, t_chunksize *chunksize)
{
	int	res;
	int	chunk_i;

	chunk_i = dispatch_by_chunk(chunksize, state->a);
	if (chunk_i == 0)
		return (pb(state));
	else if (chunk_i == 1)
	{
		res = pb(state);
		if (res < 0)
			return (res);
		if (state->b->size > 1)
			return (rb(state));
	}
	else if (chunk_i == 2)
	{
		if (state->a->size > 1)
			return (ra(state));
	}
	else
		return (CODE_ERROR_INVALID_VALUE);
	return (CODE_OK);
}

int	divide_a_to_b(t_state *state, t_chunksize *chunksize, int depth)
{
	int	i;
	int	res;

	if (state->b->size == 0)
		chunksize->clean = 1;
	i = 0;
	while (i < depth)
	{
		if (chunksize->clean)
			res = dispatch_a_to_b_clean(state, chunksize);
		else
		res = dispatch_a_to_b(state, chunksize);
		if (res < 0)
			return (res);
		i++;
	}
	return (CODE_OK);
}

int	sort_a_to_b(t_state *state, int depth)
{
	int			res;
	t_chunksize	chunksize;

	if (is_stack_sorted(state->a, SORT_ASC))
		return (CODE_OK);
	if (depth <= 3)
		return (manual_sort_a_to_b(state, depth));
	res = analyse_chunk(&chunksize, state->a, depth);
	if (res < 0)
		return (res);
	res = divide_a_to_b(state, &chunksize, depth);
	if (res < 0)
		return (res);
	if (!chunksize.clean)
	res = rev_rotate_a_to_b(state, &chunksize);
	if (res < 0)
		return (res);
	res = sort_a_to_b(state, chunksize.size[2]);
	if (res < 0)
		return (res);
	res = sort_b_to_a(state, chunksize.size[1]);
	if (res < 0)
		return (res);
	return (sort_b_to_a(state, chunksize.size[0]));
}
