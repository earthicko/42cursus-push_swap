/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:13 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:13 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "deque.h"
# include "array.h"

t_array	*parse_args(int argc, char **argv);
int		construct_stack(t_deque *stack, t_array *arr);

int		ft_atoi_if_valid(char *str, int *ret);
char	**ft_split_space(char const *s);
void	free_strs(char **strs);
int		ft_isspace(char c);
#endif
