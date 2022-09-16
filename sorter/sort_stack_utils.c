#include <limits.h>
#include "sorter.h"
#include "libft.h"

void	analyse_chunk(t_chunksize *size, t_deque *stack, int depth)
{
	int		i;
	t_node	*node;

	size->div[0] = INT_MAX;
	size->div[3] = INT_MIN;
	ft_memset(size->size, 0, sizeof(size->size));
	node = stack->head;
	i = 0;
	while (i < depth)
	{
		if (node->idx < size->div[0])
			size->div[0] = node->idx;
		if (node->idx > size->div[3])
			size->div[3] = node->idx;
		node = node->next;
		i++;
	}
	size->div[1] = size->div[0] + (size->div[3] - size->div[0]) / 3;
	size->div[2] = size->div[0] + 2 * (size->div[3] - size->div[0]) / 3;
}

int	dispatch_by_chunk(t_chunksize *chunksize, t_deque *stack)
{
	int	idx;
	int	chunk_i;

	idx = stack->head->idx;
	if (chunksize->div[0] <= idx && idx < chunksize->div[1])
		chunk_i = 0;
	else if (chunksize->div[1] <= idx && idx < chunksize->div[2])
		chunk_i = 1;
	else if (chunksize->div[2] <= idx && idx <= chunksize->div[3])
		chunk_i = 2;
	else
		return (CODE_ERROR_INVALID_VALUE);
	chunksize->size[chunk_i]++;
	return (chunk_i);
}
