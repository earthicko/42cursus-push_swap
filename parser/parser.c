/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:38 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:39 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"
#include "datatype_conversion.h"

int	append_to_array_if_valid(t_array *arr, char *arg_split)
{
	int	res;
	int	arg;

	res = ft_atoi_if_valid(arg_split, &arg);
	if (res < 0)
		return (res);
	return (array_append(arr, arg));
}

void	init_append_arg_to_array(char **args, int *n_split, int *res, int *i)
{
	*n_split = 0;
	while (args[*n_split])
		(*n_split)++;
	*res = CODE_OK;
	*i = 0;
}

int	append_arg_to_array(t_array *arr, char *arg)
{
	char	**arg_split;
	int		n_split;
	int		res;
	int		i;

	arg_split = ft_split_space(arg);
	if (!arg_split)
		return (CODE_ERROR_MALLOC);
	init_append_arg_to_array(arg_split, &n_split, &res, &i);
	if (n_split <= 0)
		res = CODE_ERROR_NOT_A_NUMBER;
	else if (n_split == 1)
		res = append_to_array_if_valid(arr, arg_split[0]);
	else
	{
		while (arg_split[i])
		{
			res = append_arg_to_array(arr, arg_split[i]);
			if (res < 0)
				break ;
			i++;
		}
	}
	free_strs(arg_split);
	return (res);
}

static t_array	*parse_args(int argc, char **argv)
{
	t_array	*ints;
	int		i;
	int		res;

	ints = array_init(argc);
	if (!ints)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		res = append_arg_to_array(ints, argv[i]);
		if (res < 0)
		{
			array_del(ints);
			return (NULL);
		}
		i++;
	}
	return (ints);
}

t_state	*parse_stack(int argc, char **argv)
{
	t_state	*state;
	t_array	*arr;

	arr = parse_args(argc, argv);
	if (!arr)
		return (NULL);
	state = state_init(arr);
	array_del(arr);
	return (state);
}
