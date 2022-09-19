/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_manual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:52 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

int	sort_a_2x(t_state *state)
{
	if (state->a->size < 2)
		return (CODE_ERROR_INVALID_VALUE);
	if (state->a->head->idx > state->a->head->next->idx)
		sa(state, 1);
	return (CODE_OK);
}

int	sort_b_2x(t_state *state)
{
	if (state->b->size < 2)
		return (CODE_ERROR_INVALID_VALUE);
	if (state->b->head->idx < state->b->head->next->idx)
		sb(state, 1);
	pa(state, 1);
	pa(state, 1);
	return (CODE_OK);
}
