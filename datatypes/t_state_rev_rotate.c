#include <unistd.h>
#include "t_state.h"
#include "stack.h"
#include "libft.h"

int	rra(t_state *state)
{
	ft_putendl_fd("rra", STDOUT_FILENO);
	return (stack_rev_rotate(state->a));
}

int	rrb(t_state *state)
{
	ft_putendl_fd("rrb", STDOUT_FILENO);
	return (stack_rev_rotate(state->b));
}

int	rrr(t_state *state)
{
	int	res[2];

	ft_putendl_fd("rrr", STDOUT_FILENO);
	res[0] = rra(state);
	res[1] = rrb(state);
	if (res[0] == CODE_OK && res[1] == CODE_OK)
		return (CODE_OK);
	return (CODE_ERROR_STACK_TOO_SMALL);
}
