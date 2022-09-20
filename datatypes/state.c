/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:32:15 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:32:16 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "datatype_conversion.h"

t_state	*state_init(t_array *arr)
{
	t_state	*init;

	init = (t_state *)malloc(sizeof(t_state));
	if (!init)
		return (NULL);
	init->a = stack_init_from_array(arr);
	if (!init->a)
	{
		free(init);
		return (NULL);
	}
	init->b = deque_init();
	if (!init->b)
	{
		deque_del(init->a);
		free(init);
		return (NULL);
	}
	return (init);
}

void	state_del(t_state *state)
{
	deque_del(state->a);
	deque_del(state->b);
	free(state);
}

int	do_n_times(t_state *state, int f(t_state *, int), int n, int echo)
{
	int	res;
	int	i;

	i = 0;
	while (i < n)
	{
		res = f(state, echo);
		if (res < 0)
			return (res);
		i++;
	}
	return (CODE_OK);
}
