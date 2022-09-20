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
# include "array.h"
# include "state.h"

t_state	*parse_stack(int argc, char **argv);
t_array	*parse_args(int argc, char **argv);

int		ft_atoi_if_valid(char *str, int *ret);
char	**ft_split_space(char const *s);
#endif
