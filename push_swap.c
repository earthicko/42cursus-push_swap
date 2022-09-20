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

#include <unistd.h>
#include "parser.h"
#include "sorter.h"

int	main(int argc, char **argv)
{
	t_state	*state;
	int		res;

	state = parse_stack(argc, argv);
	if (!state)
	{
		ft_putendl_fd(STR_ERROR, STDERR_FILENO);
		return (CODE_ERROR_GENERIC);
	}
	res = sort_a_to_b(state, state->a->size);
	if (res < 0)
		ft_putendl_fd(STR_ERROR, STDERR_FILENO);
	state_del(state);
	return (res);
}
