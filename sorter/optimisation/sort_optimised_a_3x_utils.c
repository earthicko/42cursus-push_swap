/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimised_a_3x_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:27:39 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:40 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	sort_a_3x_021(t_state *state, int clean)
{
	if (clean)
	{
		rra(state, 1);
		sa(state, 1);
	}
	else
	{
		ra(state, 1);
		sa(state, 1);
		rra(state, 1);
	}
}

void	sort_a_3x_102(t_state *state, int clean)
{
	if (clean)
	{
		sa(state, 1);
	}
	else
	{
		sa(state, 1);
	}
}

void	sort_a_3x_120(t_state *state, int clean)
{
	if (clean)
	{
		rra(state, 1);
	}
	else
	{
		ra(state, 1);
		sa(state, 1);
		rra(state, 1);
		sa(state, 1);
	}
}

void	sort_a_3x_201(t_state *state, int clean)
{
	if (clean)
	{
		ra(state, 1);
	}
	else
	{
		ra(state, 1);
		pb(state, 1);
		pb(state, 1);
		rra(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
}

void	sort_a_3x_210(t_state *state, int clean)
{
	if (clean)
	{
		sa(state, 1);
		rra(state, 1);
	}
	else
	{
		ra(state, 1);
		pb(state, 1);
		pb(state, 1);
		rra(state, 1);
		pa(state, 1);
		pa(state, 1);
		sa(state, 1);
	}
}
