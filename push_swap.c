/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:31:31 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:31:32 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include "sorter.h"

int	parse_stack(t_state *state, int argc, char **argv)
{
	t_array	*arr;
	int		res;

	arr = parse_args(argc, argv);
	if (!arr)
		return (CODE_ERROR_MALLOC);
	res = construct_stack(state->a, arr);
	array_del(arr);
	return (res);
}

int	main(int argc, char **argv)
{
	t_state	*state;
	int		res;

	state = state_init();
	if (!state)
	{
		ft_putendl_fd(STR_ERROR, STDERR_FILENO);
		return (CODE_ERROR_MALLOC);
	}
	res = parse_stack(state, argc, argv);
	if (res < 0)
	{
		state_del(state);
		ft_putendl_fd(STR_ERROR, STDERR_FILENO);
		return (res);
	}
	res = sort_a_to_b(state, state->a->size);
	state_del(state);
	return (res);
}
