/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_swap_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:24 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:25 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "state.h"
#include "stack.h"
#include "libft.h"

int	sa(t_state *state)
{
	int	res;

	res = deque_push_tail_idx(state->print_queue, SA);
	if (res < 0)
		return (res);
	return (stack_swap(state->a));
}

int	sb(t_state *state)
{
	int	res;

	res = deque_push_tail_idx(state->print_queue, SB);
	if (res < 0)
		return (res);
	return (stack_swap(state->b));
}

int	ss(t_state *state)
{
	int	res[2];

	res[0] = deque_push_tail_idx(state->print_queue, SS);
	if (res[0] < 0)
		return (res[0]);
	res[0] = stack_swap(state->a);
	res[1] = stack_swap(state->b);
	if (res[0] == CODE_OK && res[1] == CODE_OK)
		return (CODE_OK);
	return (CODE_ERROR_STACK_TOO_SMALL);
}

int	pa(t_state *state)
{
	int	res;

	res = deque_push_tail_idx(state->print_queue, PA);
	if (res < 0)
		return (res);
	return (stack_push(state->b, state->a));
}

int	pb(t_state *state)
{
	int	res;

	res = deque_push_tail_idx(state->print_queue, PB);
	if (res < 0)
		return (res);
	return (stack_push(state->a, state->b));
}
