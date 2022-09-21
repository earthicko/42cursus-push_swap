/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:22 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:23 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "state.h"
#include "stack.h"
#include "libft.h"

int	ra(t_state *state)
{
	if (echo)
		ft_putendl_fd("ra", STDOUT_FILENO);
	return (stack_rotate(state->a));
}

int	rb(t_state *state)
{
	if (echo)
		ft_putendl_fd("rb", STDOUT_FILENO);
	return (stack_rotate(state->b));
}

int	rr(t_state *state)
{
	int	res[2];

	if (echo)
		ft_putendl_fd("rr", STDOUT_FILENO);
	res[0] = stack_rotate(state->a);
	res[1] = stack_rotate(state->b);
	if (res[0] == CODE_OK && res[1] == CODE_OK)
		return (CODE_OK);
	return (CODE_ERROR_STACK_TOO_SMALL);
}
