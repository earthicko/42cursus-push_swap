#include "t_state.h"
#include "libft.h"

t_state	*state_init(void)
{
	t_state	*init;
	init = (t_state *)malloc(sizeof(t_state));
	if (!init)
		return (NULL);
	ft_memset(init, 0, sizeof(t_state));
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
