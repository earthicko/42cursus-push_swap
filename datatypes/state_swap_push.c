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

int	sa(t_state *state, int echo)
{
	if (echo)
		ft_putendl_fd("sa", STDOUT_FILENO);
	return (stack_swap(state->a));
}

int	sb(t_state *state, int echo)
{
	if (echo)
		ft_putendl_fd("sb", STDOUT_FILENO);
	return (stack_swap(state->b));
}

int	ss(t_state *state, int echo)
{
	int	res[2];

	if (echo)
		ft_putendl_fd("ss", STDOUT_FILENO);
	res[0] = stack_swap(state->a);
	res[1] = stack_swap(state->b);
	if (res[0] == CODE_OK && res[1] == CODE_OK)
		return (CODE_OK);
	return (CODE_ERROR_STACK_TOO_SMALL);
}

int	pa(t_state *state, int echo)
{
	if (echo)
		ft_putendl_fd("pa", STDOUT_FILENO);
	return (stack_push(state->b, state->a));
}

int	pb(t_state *state, int echo)
{
	if (echo)
		ft_putendl_fd("pb", STDOUT_FILENO);
	return (stack_push(state->a, state->b));
}
