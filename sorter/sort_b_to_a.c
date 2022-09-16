#include "sorter.h"

int	manual_sort_b_to_a(t_state *state, int depth)
{
	if (depth == 0)
		return (CODE_OK);
	if (depth == 1)
		return (pa(state));
	if (depth == 2)
		return (sort_two_b(state));
	return (CODE_ERROR_INVALID_VALUE);
}

int	rev_rotate_b_to_a(t_state *state, t_chunksize *chunksize)
{
	int	n_rrr;
	int	res;

	n_rrr = chunksize->size[0];
	if (chunksize->size[1] < n_rrr)
		n_rrr = chunksize->size[1];
	res = do_n_times(state, rrr, n_rrr);
	if (res < 0)
		return (res);
	res = do_n_times(state, rra, chunksize->size[1] - n_rrr);
	if (res < 0)
		return (res);
	res = do_n_times(state, rrb, chunksize->size[0] - n_rrr);
	return (res);
}

int	dispatch_b_to_a(t_state *state, t_chunksize *chunksize)
{
	int	chunk_i;
	int	res;

	chunk_i = dispatch_by_chunk(chunksize, state->b);
	if (chunk_i == 0)
		return (rb(state));
	else if (chunk_i == 1)
	{
		res = pa(state);
		if (res < 0)
			return (res);
		return (ra(state));
	}
	else if (chunk_i == 2)
		return (pa(state));
	else
		return (CODE_ERROR_INVALID_VALUE);
}

int	divide_b_to_a(t_state *state, t_chunksize *chunksize, int depth)
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

	if (depth <= 2)
		return (manual_sort_b_to_a(state, depth));
	analyse_chunk(&chunksize, state->b, depth);
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
	res = do_n_times(state, pa, chunksize.size[0]);
	if (res < 0)
		return (res);
	return (sort_a_to_b(state, chunksize.size[0]));
}
