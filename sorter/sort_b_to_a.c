/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:50 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:51 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

static int	rev_rotate_b_to_a(t_state *state, t_chunksize *chunksize)
{
	int	n_rra;
	int	n_rrb;
	int	n_rrr;
	int	res;

	n_rra = chunksize->size[1];
	n_rrb = chunksize->size[0];
	if (state->a->size < 2)
		n_rra = 0;
	if (state->b->size < 2)
		n_rrb = 0;
	if (n_rra < n_rrb)
		n_rrr = n_rra;
	else
		n_rrr = n_rrb;
	res = do_n_times(state, rrr, n_rrr, 1);
	if (res < 0)
		return (res);
	res = do_n_times(state, rra, n_rra - n_rrr, 1);
	if (res < 0)
		return (res);
	res = do_n_times(state, rrb, n_rrb - n_rrr, 1);
	return (res);
}

static int	dispatch_b_to_a(t_state *state, t_chunksize *chunksize)
{
	int	chunk_i;
	int	res;

	chunk_i = dispatch_by_chunk(chunksize, state->b);
	if (chunk_i == 0)
	{
		if (state->b->size > 1)
			return (rb(state, 1));
	}
	else if (chunk_i == 1)
	{
		res = pa(state, 1);
		if (res < 0)
			return (res);
		if (state->a->size > 1)
			return (ra(state, 1));
	}
	else if (chunk_i == 2)
		return (pa(state, 1));
	else
		return (CODE_ERROR_INVALID_VALUE);
	return (CODE_OK);
}

static int	divide_b_to_a(t_state *state, t_chunksize *chunksize, int depth)
{
	int	i;
	int	res;

	i = 0;
	while (i < depth)
	{
		res = dispatch_b_to_a(state, chunksize);
		if (res < 0)
			return (res);
		i++;
	}
	return (CODE_OK);
}

int	sort_b_to_a(t_state *state, int depth)
{
	int			res;
	t_chunksize	chunksize;

	res = is_stack_optimisable(state, state->b, depth);
	if (res)
		return (sort_optimally(state, state->b, res, depth));
	res = analyse_chunk(&chunksize, state->b, depth);
	if (res < 0)
		return (res);
	res = divide_b_to_a(state, &chunksize, depth);
	if (res < 0)
		return (res);
	res = sort_a_to_b(state, chunksize.size[2]);
	if (res < 0)
		return (res);
	res = rev_rotate_b_to_a(state, &chunksize);
	if (res < 0)
		return (res);
	res = sort_a_to_b(state, chunksize.size[1]);
	if (res < 0)
		return (res);
	res = do_n_times(state, pa, chunksize.size[0], 1);
	if (res < 0)
		return (res);
	return (sort_a_to_b(state, chunksize.size[0]));
}
