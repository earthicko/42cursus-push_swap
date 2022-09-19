/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_debug.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:28:52 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:53 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_DEBUG_H
# define DEQUE_DEBUG_H
# include "deque.h"

void	print_node(t_node *node);
void	print_deque(t_deque *deque);

void	print_node_title(t_node *node);
void	print_node_prev(t_node *node);
void	print_node_next(t_node *node);
void	print_node_idx(t_node *node);
#endif
