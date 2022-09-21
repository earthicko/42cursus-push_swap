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

static int	rev_rotate_a_to_b(t_state *state, t_chunksize *chunksize)
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

static int	dispatch_a_to_b(t_state *state, t_chunksize *chunksize)
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

static int	divide_a_to_b(t_state *state, t_chunksize *chunksize, int depth)
{
	int	i;
	int	res;

	if (state->b->size == 0 && state->a->size == depth)
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

	res = is_stack_optimisable(state, state->a, depth);
	if (res)
		return (sort_optimally(state, state->a, res, depth));
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
