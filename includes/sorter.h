#ifndef SORTER_H
# define SORTER_H
# include "t_state.h"

int	sort_stack(t_state *state);
int	sort_a_to_b(t_state *state, int s, int e);
int	sort_b_to_a(t_state *state, int s, int e);
int	sort_two_a(t_state *state);
int	sort_two_b(t_state *state);
#endif
