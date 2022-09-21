/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimised_3x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:27:37 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:38 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	sort_a_3x(t_state *state, int clean)
{
	int	head[3];

	if (clean == 1 && state->a->size != 3)
		return (CODE_ERROR_INVALID_VALUE);
	if (clean == 0 && state->a->size < 3)
		return (CODE_ERROR_INVALID_VALUE);
	head[0] = state->a->head->idx;
	head[1] = state->a->head->next->idx;
	head[2] = state->a->head->next->next->idx;
	if (head[0] < head[2] && head[2] < head[1])
		sort_a_3x_021(state, clean);
	else if (head[1] < head[0] && head[0] < head[2])
		sort_a_3x_102(state, clean);
	else if (head[2] < head[0] && head[0] < head[1])
		sort_a_3x_120(state, clean);
	else if (head[1] < head[2] && head[2] < head[0])
		sort_a_3x_201(state, clean);
	else if (head[2] < head[1] && head[1] < head[0])
		sort_a_3x_210(state, clean);
	return (CODE_OK);
}

int	sort_b_3x(t_state *state, int clean)
{
	int	head[3];

	if (clean == 1 && state->b->size != 3)
		return (CODE_ERROR_INVALID_VALUE);
	if (clean == 0 && state->b->size < 3)
		return (CODE_ERROR_INVALID_VALUE);
	head[0] = state->b->head->idx;
	head[1] = state->b->head->next->idx;
	head[2] = state->b->head->next->next->idx;
	if (head[0] < head[1] && head[1] < head[2])
		sort_b_3x_012(state, clean);
	else if (head[0] < head[2] && head[2] < head[1])
		sort_b_3x_021(state, clean);
	else if (head[1] < head[0] && head[0] < head[2])
		sort_b_3x_102(state, clean);
	else if (head[2] < head[0] && head[0] < head[1])
		sort_b_3x_120(state, clean);
	else if (head[1] < head[2] && head[2] < head[0])
		sort_b_3x_201(state, clean);
	else if (head[2] < head[1] && head[1] < head[0])
		do_n_times(state, pa, 3);
	return (CODE_OK);
}
