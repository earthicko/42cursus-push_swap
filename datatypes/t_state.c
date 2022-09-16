#include "t_state.h"

t_state	*state_init(void)
{
	t_state	*init;

	init = (t_state *)malloc(sizeof(t_state));
	if (!init)
		return (NULL);
	init->a = deque_init();
	if (!init->a)
	{
		free(init);
		return (NULL);
	}
	init->b = deque_init();
	if (!init->b)
	{
		deque_del(init->a);
		free(init);
		return (NULL);
	}
	return (init);
}

void	state_del(t_state *state)
{
	deque_del(state->a);
	deque_del(state->b);
	free(state);
}

int	do_n_times(t_state *state, int f(t_state *), int n)
{
	int	res;
	int	i;

	i = 0;
	while (i < n)
	{
		res = f(state);
		if (res < 0)
			return (res);
		i++;
	}
	return (CODE_OK);
}
