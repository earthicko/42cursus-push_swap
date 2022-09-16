#ifndef STATE_H
# define STATE_H
# include "deque.h"

typedef struct s_state
{
	t_deque	*a;
	t_deque	*b;
}	t_state;

typedef struct s_chunksize
{
	int		div[4];
	int		size[3];
}	t_chunksize;

t_state	*state_init(void);
void	state_del(t_state *state);
int		do_n_times(t_state *state, int f(t_state *), int n);

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
