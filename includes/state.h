/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:20 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:21 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H
# include "codes.h"
# include "deque.h"
# include "array.h"

enum e_op
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	NONE
};

typedef struct s_state
{
	t_deque	*a;
	t_deque	*b;
	t_deque	*print_queue;
}	t_state;

typedef struct s_chunksize
{
	int	clean;
	int	div[4];
	int	size[3];
}	t_chunksize;

t_state	*state_init(t_array *arr);
void	state_del(t_state *state);
void	merge_operations(t_state *state);
void	state_print_op_queue(t_state *state);
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
