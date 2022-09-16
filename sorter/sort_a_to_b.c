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
		return (sort_two_a(state));
	return (CODE_ERROR_INVALID_VALUE);
}

int	rev_rotate_a_to_b(t_state *state, t_chunksize *chunksize)
{
	int	n_rrr;
	int	res;

	n_rrr = chunksize->size[1];
	if (chunksize->size[2] < n_rrr)
		n_rrr = chunksize->size[2];
	res = do_n_times(state, rrr, n_rrr);
	if (res < 0)
		return (res);
	res = do_n_times(state, rrb, chunksize->size[1] - n_rrr);
	if (res < 0)
		return (res);
	res = do_n_times(state, rra, chunksize->size[2] - n_rrr);
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
		return (rb(state));
	}
	else if (chunk_i == 2)
		return (ra(state));
	else
		return (CODE_ERROR_INVALID_VALUE);
}

int	divide_a_to_b(t_state *state, t_chunksize *chunksize, int depth)
{
	int	i;
	int	res;

	i = 0;
	while (i < depth)
	{
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

	if (depth <= 2)
		return (manual_sort_a_to_b(state, depth));
	analyse_chunk(&chunksize, state->a, depth);
	res = divide_a_to_b(state, &chunksize, depth);
	if (res < 0)
		return (res);
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
