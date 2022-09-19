/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:28:16 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:17 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "state_debug.h"

void	print_one_stack_layer(t_state *state, int i_line, t_node *a, t_node *b)
{
	if (i_line < state->a->size)
	{
		printf("%2d", a->idx);
		a = a->next;
	}
	else
		printf("  ");
	printf(" | ");
	if (i_line < state->b->size)
	{
		printf("%2d", b->idx);
		b = b->next;
	}
	else
		printf("  ");
	printf("\n");
}

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
		print_one_stack_layer(state, i, a, b);
		i++;
	}
	printf("-------\n");
}
