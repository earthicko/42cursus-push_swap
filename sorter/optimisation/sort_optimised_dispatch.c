/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimised_dispatch.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:27:43 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:44 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	dispatch_a_to_b_clean(t_state *state, t_chunksize *chunksize)
{
	int	res;
	int	chunk_i;

	chunk_i = dispatch_by_chunk(chunksize, state->a);
	if (chunk_i == 0)
	{
		res = pb(state);
		if (res < 0)
			return (res);
		if (state->b->size > 1)
			return (rb(state));
	}
	else if (chunk_i == 1)
		return (pb(state));
	else if (chunk_i == 2)
	{
		if (state->a->size > 1)
			return (ra(state));
	}
	else
		return (CODE_ERROR_INVALID_VALUE);
	return (CODE_OK);
}
