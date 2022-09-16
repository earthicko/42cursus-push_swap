#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include "sorter.h"

#include "t_deque_debug.h"

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
		ft_putendl_fd(STR_ERROR, STDOUT_FILENO);
		return (CODE_ERROR_MALLOC);
	}
	res = parse_stack(state, argc, argv);
	if (res < 0)
	{
		state_del(state);
		ft_putendl_fd(STR_ERROR, STDOUT_FILENO);
		return (res);
	}
	res = sort_a_to_b(state, state->a->size);
	state_del(state);
	return (res);
}
