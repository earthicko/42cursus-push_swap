#include <unistd.h>
#include "state.h"
#include "stack.h"
#include "libft.h"

int	ra(t_state *state)
{
	ft_putendl_fd("ra", STDOUT_FILENO);
	return (stack_rotate(state->a));
}

int	rb(t_state *state)
{
	ft_putendl_fd("rb", STDOUT_FILENO);
	return (stack_rotate(state->b));
}

int	rr(t_state *state)
{
	int	res[2];

	ft_putendl_fd("rr", STDOUT_FILENO);
	res[0] = ra(state);
	res[1] = rb(state);
	if (res[0] == CODE_OK && res[1] == CODE_OK)
		return (CODE_OK);
	return (CODE_ERROR_STACK_TOO_SMALL);
}
