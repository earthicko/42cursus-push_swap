/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_optimised_b_3x_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:27:41 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:27:42 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"

void	sort_b_3x_021(t_state *state, int clean)
{
	if (clean)
	{
		rb(state, 1);
		pa(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
	else
	{
		rb(state, 1);
		pa(state, 1);
		pa(state, 1);
		rrb(state, 1);
		pa(state, 1);
	}
}

void	sort_b_3x_102(t_state *state, int clean)
{
	if (clean)
	{
		rrb(state, 1);
		pa(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
	else
	{
		rb(state, 1);
		rb(state, 1);
		pa(state, 1);
		rrb(state, 1);
		rrb(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
}

void	sort_b_3x_120(t_state *state, int clean)
{
	if (clean)
	{
		sb(state, 1);
		pa(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
	else
	{
		sb(state, 1);
		pa(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
}

void	sort_b_3x_201(t_state *state, int clean)
{
	if (clean)
	{
		pa(state, 1);
		sb(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
	else
	{
		pa(state, 1);
		sb(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
}

void	sort_b_3x_210(t_state *state, int clean)
{
	if (clean)
	{
		pa(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
	else
	{
		pa(state, 1);
		pa(state, 1);
		pa(state, 1);
	}
}
