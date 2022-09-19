/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:19 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:20 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "state.h"
#include "stack.h"
#include "libft.h"

int	rra(t_state *state, int echo)
{
	if (echo)
		ft_putendl_fd("rra", STDOUT_FILENO);
	return (stack_rev_rotate(state->a));
}

int	rrb(t_state *state, int echo)
{
	if (echo)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	return (stack_rev_rotate(state->b));
}

int	rrr(t_state *state, int echo)
{
	int	res[2];

	if (echo)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	res[0] = stack_rev_rotate(state->a);
	res[1] = stack_rev_rotate(state->b);
	if (res[0] == CODE_OK && res[1] == CODE_OK)
		return (CODE_OK);
	return (CODE_ERROR_STACK_TOO_SMALL);
}
