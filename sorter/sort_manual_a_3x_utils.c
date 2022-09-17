#include "state.h"

void	sort_a_3x_021(t_state *state, int clean)
{
	if (clean)
	{
		rra(state);
		sa(state);
	}
	else
	{
		ra(state);
		sa(state);
		rra(state);
	}
}

void	sort_a_3x_102(t_state *state, int clean)
{
	if (clean)
	{
		sa(state);
	}
	else
	{
		sa(state);
	}
}

void	sort_a_3x_120(t_state *state, int clean)
{
	if (clean)
	{
		rra(state);
	}
	else
	{
		ra(state);
		sa(state);
		rra(state);
		sa(state);
	}
}

void	sort_a_3x_201(t_state *state, int clean)
{
	if (clean)
	{
		ra(state);
	}
	else
	{
		ra(state);
		pb(state);
		pb(state);
		rra(state);
		pa(state);
		pa(state);
	}
}

void	sort_a_3x_210(t_state *state, int clean)
{
	if (clean)
	{
		sa(state);
		rra(state);
	}
	else
	{
		ra(state);
		pb(state);
		pb(state);
		rra(state);
		pa(state);
		pa(state);
		sa(state);
	}
}
