#ifndef SORTER_H
# define SORTER_H
# include "state.h"

int		sort_a_to_b(t_state *state, int depth);
int		sort_b_to_a(t_state *state, int depth);
int		sort_two_a(t_state *state);
int		sort_two_b(t_state *state);

void	analyse_chunk(t_chunksize *chunksize, t_deque *stack, int depth);
int		dispatch_by_chunk(t_chunksize *chunksize, t_deque *stack);
#endif
