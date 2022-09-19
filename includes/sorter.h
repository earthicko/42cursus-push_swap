/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:14 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:15 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H
# include "state.h"
# define CODE_STACK_NOT_OPTIMISABLE 0
# define CODE_STACK_SORTED 1
# define CODE_STACK_SMALL_ENOUGH 2

int		sort_a_to_b(t_state *state, int depth);
int		sort_b_to_a(t_state *state, int depth);

int		analyse_chunk(t_chunksize *chunksize, t_deque *stack, int depth);
int		dispatch_by_chunk(t_chunksize *chunksize, t_deque *stack);
int		is_stack_optimisable(t_state *state, t_deque *stack, int depth);
int		sort_optimally(t_state *state, t_deque *stack, int code, int depth);

int		dispatch_a_to_b_clean(t_state *state, t_chunksize *chunksize);

int		manual_sort_a_to_b(t_state *state, int depth);
int		manual_sort_b_to_a(t_state *state, int depth);

int		sort_a_2x(t_state *state);
int		sort_b_2x(t_state *state);

int		sort_a_3x(t_state *state, int clean);
void	sort_a_3x_021(t_state *state, int clean);
void	sort_a_3x_102(t_state *state, int clean);
void	sort_a_3x_120(t_state *state, int clean);
void	sort_a_3x_201(t_state *state, int clean);
void	sort_a_3x_210(t_state *state, int clean);
int		sort_b_3x(t_state *state, int clean);
void	sort_b_3x_021(t_state *state, int clean);
void	sort_b_3x_102(t_state *state, int clean);
void	sort_b_3x_120(t_state *state, int clean);
void	sort_b_3x_201(t_state *state, int clean);
void	sort_b_3x_210(t_state *state, int clean);
#endif
