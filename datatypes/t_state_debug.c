#include <stdio.h>
#include "t_state_debug.h"

void	print_state(t_state *state)
{
	int		max_len;
	int		i;
	t_node	*a;
	t_node	*b;

	max_len = state->a->size;
	if (state->b->size > max_len)
		max_len = state->b->size;
	printf("-------\n");
	a = state->a->head;
	b = state->b->head;
	i = 0;
	while (i < max_len)
	{
		if (i < state->a->size)
		{
			printf("%2d", a->idx);
			a = a->next;
		}
		else
			printf("  ");
		printf(" | ");
		if (i < state->b->size)
		{
			printf("%2d", b->idx);
			b = b->next;
		}
		else
			printf("  ");
		printf("\n");
		i++;
	}
	printf("-------\n");
}
