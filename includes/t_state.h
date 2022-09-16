#ifndef T_STATE_H
# define T_STATE_H
# include "t_deque.h"

typedef struct s_state
{
	t_deque	*a;
	t_deque	*b;
	int		min;
	int		max;
	int		mid[2];
}	t_state;

t_state	*state_init(void);
void	state_del(t_state *state);

int		sa(t_state *state);
int		sb(t_state *state);
int		ss(t_state *state);
int		pa(t_state *state);
int		pb(t_state *state);
int		ra(t_state *state);
int		rb(t_state *state);
int		rr(t_state *state);
int		rra(t_state *state);
int		rrb(t_state *state);
int		rrr(t_state *state);
#endif
