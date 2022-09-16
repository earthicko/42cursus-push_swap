#include <stdlib.h>
#include "push_swap.h"
#include "parser.h"

#include "t_deque_debug.h"

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
