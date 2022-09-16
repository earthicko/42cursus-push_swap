#include "sorter.h"
#include "libft.h"
#include "t_deque_debug.h"
#include <limits.h>
#include <stdio.h>
void	analyse_chunk(t_state *state, t_deque *stack, int s, int e)
{
	int		i;
	t_node	*node;

	state->div[0] = INT_MAX;
	state->div[3] = INT_MIN;
	ft_memset(state->chunk_size, 0, sizeof(state->chunk_size));
	node = stack->head;
	i = 0;
	while (i < s)
	{
		node = node->next;
		i++;
	}
	while (i < e)
	{
		if (node->idx < state->div[0])
			state->div[0] = node->idx;
		if (node->idx > state->div[3])
			state->div[3] = node->idx;
		node = node->next;
		i++;
	}
	state->div[1] = state->div[0] + (state->div[3] - state->div[0]) / 3;
	state->div[2] = state->div[0] + 2 * (state->div[3] - state->div[0]) / 3;
	printf("div: %d, %d, %d, %d\n", state->div[0], state->div[1], state->div[2], state->div[3]);
}
int	divide_by_chunk(t_state *state, t_deque *stack)
{
	int	idx;
	int	chunk_i;

	idx = stack->head->idx;
	if (state->div[0] <= idx && idx < state->div[1])
		chunk_i = 0;
	else if (state->div[1] <= idx && idx < state->div[2])
		chunk_i = 1;
	else if (state->div[2] <= idx && idx <= state->div[3])
		chunk_i = 2;
	else
		return (CODE_ERROR_INVALID_VALUE);
	printf("idx %d is in chunk %d\n", idx, chunk_i);
	state->chunk_size[chunk_i]++;
	return (chunk_i);
}

int	sort_stack(t_state *state)
{
	return (sort_a_to_b(state, 0, state->a->size));
}

int	sort_a_to_b(t_state *state, int s, int e)
{
	int	i;
	int	chunk_i;
	print_deque(state->a);
	print_deque(state->b);
	printf("Sort a to b, [%d : %d]\n", s, e);
	if (e - s <= 1)
		return (CODE_OK);
	if (e - s == 2)
		return (sort_two_a(state));
	analyse_chunk(state, state->a, s, e);
	printf("sifting %d nodes\n", e - s);
	i = 0;
	while (i < e - s)
	{
		chunk_i = divide_by_chunk(state, state->a);
		if (chunk_i == 0)
			pb(state);
		else if (chunk_i == 1)
		{
			pb(state);
			rb(state);
		}
		else if (chunk_i == 2)
			ra(state);
		i++;
	}
	printf("chunk size %d %d %d\n", state->chunk_size[0], state->chunk_size[1], state->chunk_size[2]);
	i = 0;
	while (i < state->chunk_size[1])
	{
		rrb(state);
		i++;
	}
	i = 0;
	while (i < state->chunk_size[2])
	{
		rra(state);
		i++;
	}
	sort_a_to_b(state, 0, state->chunk_size[2]);
	sort_b_to_a(state, 0, state->chunk_size[1]);
	sort_b_to_a(state, 0, state->chunk_size[0]);
	return (CODE_OK);
}

int	sort_b_to_a(t_state *state, int s, int e)
{
	int	i;
	int	chunk_i;
	print_deque(state->a);
	print_deque(state->b);
	printf("Sort b to a, [%d : %d]\n", s, e);
	if (e - s == 0)
		return (CODE_OK);
	if (e - s == 1)
		return (pa(state));
	if (e - s == 2)
		return (sort_two_b(state));
	analyse_chunk(state, state->b, s, e);
	printf("sifting %d nodes\n", e - s);
	i = 0;
	while (i < e - s)
	{
		chunk_i = divide_by_chunk(state, state->b);
		if (chunk_i == 0)
			rb(state);
		else if (chunk_i == 1)
		{
			pa(state);
			ra(state);
		}
		else if (chunk_i == 2)
			pa(state);
		i++;
	}
	printf("chunk size %d %d %d\n", state->chunk_size[0], state->chunk_size[1], state->chunk_size[2]);
	sort_a_to_b(state, 0, state->chunk_size[2]);
	i = 0;
	while (i < state->chunk_size[1])
	{
		rra(state);
		i++;
	}
	i = 0;
	while (i < state->chunk_size[0])
	{
		rrb(state);
		i++;
	}
	sort_a_to_b(state, 0, state->chunk_size[1]);
	i = 0;
	while (i < state->chunk_size[0])
	{
		pa(state);
		i++;
	}
	sort_a_to_b(state, 0, state->chunk_size[0]);
	return (CODE_OK);
}
