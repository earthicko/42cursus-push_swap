#include "state.h"

int	sort_two_a(t_state *state)
{
	if (state->a->size < 2)
		return (CODE_ERROR_INVALID_VALUE);
	if (state->a->head->idx > state->a->head->next->idx)
		sa(state);
	return (CODE_OK);
}

int	sort_two_b(t_state *state)
{
	if (state->b->size < 2)
		return (CODE_ERROR_INVALID_VALUE);
	if (state->b->head->idx < state->b->head->next->idx)
		sb(state);
	pa(state);
	pa(state);
	return (CODE_OK);
}
