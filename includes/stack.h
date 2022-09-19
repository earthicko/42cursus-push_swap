/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:16 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:17 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "codes.h"
# include "deque.h"

int	stack_swap(t_deque *this);
int	stack_push(t_deque *from, t_deque *to);
int	stack_rotate(t_deque *this);
int	stack_rev_rotate(t_deque *this);
#endif
