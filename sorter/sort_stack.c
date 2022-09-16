#include "sorter.h"
#include <limits.h>
#include <stdio.h>
void	find_min_max(t_state *state, t_deque *stack, int s, int e)
{
	int		i;
	t_node	*node;

	state->min = INT_MAX;
	state->max = INT_MIN;
	node = stack->head;
	i = 0;
	while (i < s)
	{
		node = node->next;
		i++;
	}
	while (i < e)
	{
		if (node->idx < state->min)
			state->min = node->idx;
		if (node->idx > state->max)
			state->max = node->idx;
		node = node->next;
		i++;
	}
	printf("min: %d, max: %d\n", state->min, state->max);
	state->mid[0] = state->min + (state->max - state->min) / 3;
	state->mid[1] = state->min + 2 * (state->max - state->min) / 3;
	printf("mid: %d, %d\n", state->mid[0], state->mid[1]);
}

int	sort_stack(t_state *state)
{
	return (sort_a_to_b(state, 0, state->a->size));
}

int	sort_a_to_b(t_state *state, int s, int e)
{
	printf("Sort a to b, [%d : %d]\n", s, e);
	if (e - s <= 1)
		return (CODE_OK);
	find_min_max(state, state->a, s, e);

	return (CODE_OK);
}

int	sort_b_to_a(t_state *state, int s, int e)
{
	printf("Sort b to a, [%d : %d]\n", s, e);
	if (e - s <= 1)
		return (CODE_OK);
	find_min_max(state, state->b, s, e);

	return (CODE_OK);
}
