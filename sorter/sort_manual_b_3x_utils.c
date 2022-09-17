#include "state.h"

void	sort_b_3x_021(t_state *state, int clean)
{
	if (clean)
	{
		rb(state);
		pa(state);
		pa(state);
		pa(state);
	}
	else
	{
		rb(state);
		pa(state);
		pa(state);
		rrb(state);
		pa(state);
	}
}

void	sort_b_3x_102(t_state *state, int clean)
{
	if (clean)
	{
		rrb(state);
		pa(state);
		pa(state);
		pa(state);
	}
	else
	{
		rb(state);
		rb(state);
		pa(state);
		rrb(state);
		rrb(state);
		pa(state);
	}
}

void	sort_b_3x_120(t_state *state, int clean)
{
	if (clean)
	{
		sb(state);
		pa(state);
		pa(state);
		pa(state);
	}
	else
	{
		sb(state);
		pa(state);
		pa(state);
		pa(state);
	}
}

void	sort_b_3x_201(t_state *state, int clean)
{
	if (clean)
	{
		pa(state);
		sb(state);
		pa(state);
		pa(state);
	}
	else
	{
		pa(state);
		sb(state);
		pa(state);
		pa(state);
	}
}

void	sort_b_3x_210(t_state *state, int clean)
{
	if (clean)
	{
		pa(state);
		pa(state);
		pa(state);
	}
	else
	{
		pa(state);
		pa(state);
		pa(state);
	}
}
