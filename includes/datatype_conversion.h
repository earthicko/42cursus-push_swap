/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatype_conversion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:50:38 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/20 16:50:40 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPE_CONVERSION_H
# define DATATYPE_CONVERSION_H
# include "array.h"
# include "deque.h"

t_array	*array_init_from_stack(t_deque *stack, int depth);
int		stack_init_from_array(t_deque *stack, t_array *arr);
#endif
