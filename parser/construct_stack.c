#include "parser.h"

int	construct_stack(t_deque *stack, t_array *arr)
{
	t_node	*node;
	int		i;
	int		j;
	int		idx;
	
	i = 0;
	while (i < arr->len)
	{
		idx = 0;
		j = 0;
		while (j < arr->len)
		{
			if (j != i && arr->data[j] == arr->data[i])
				return (CODE_ERROR_INVALID_VALUE);
			if (arr->data[j] < arr->data[i])
				idx++;
			j++;
		}
		node = node_init(idx);
		if (!node)
			return (CODE_ERROR_MALLOC);
		deque_push_tail(stack, node);
		i++;
	}
	return (CODE_OK);
}
