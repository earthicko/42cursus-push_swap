#include <stdlib.h>
#include "push_swap.h"
#include "parser.h"

void	state_del(t_state *state)
{
	deque_del(state->a);
	deque_del(state->b);
	free(state);
}

int	init_push_swap(t_state **state)
{
	*state = (t_state *)malloc(sizeof(t_state));
	if (!(*state))
		return (CODE_ERROR_MALLOC);
	(*state)->a = deque_init();
	if (!(*state)->a)
	{
		free(*state);
		return (CODE_ERROR_MALLOC);
	}
	(*state)->b = deque_init();
	if (!(*state)->b)
	{
		deque_del((*state)->a);
		free(*state);
		return (CODE_ERROR_MALLOC);
	}
	return (CODE_OK);
}

int	parse_stack(t_state *state, int argc, char **argv)
{
	t_array	*arr;

	arr = parse_args(argc, argv);
	if (!arr)
		return (CODE_ERROR_MALLOC);
	
}

int	sort_stack(t_state *state)
{
	//
}

int	main(int argc, char **argv)
{
	t_state	*state;
	int		res;

	res = init_push_swap(&state);
	if (res < 0)
		return (res);
	res = parse_stack(state, argc, argv);
	if (res < 0)
	{
		state_del(state);
		return (res);
	}
	res = sort_stack(state);
	state_del(state);
	return (res);
}
