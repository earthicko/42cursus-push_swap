/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:31:31 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:31:32 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parser.h"
#include "sorter.h"
#include "get_next_line.h"

int	parse_and_execute_swap_push(t_state *state, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(state, 0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(state, 0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(state, 0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(state, 0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(state, 0);
	else
		return (CODE_ERROR_INVALID_VALUE);
	return (CODE_OK);
}

int	parse_and_execute_rotate(t_state *state, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(state, 0);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(state, 0);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(state, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(state, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(state, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(state, 0);
	else
		return (CODE_ERROR_INVALID_VALUE);
	return (CODE_OK);
}

int	parse_and_execute(t_state *state, char *line)
{
	if (line[0] == 's' || line[0] == 'p')
		return (parse_and_execute_swap_push(state, line));
	if (line[0] == 'r')
		return (parse_and_execute_rotate(state, line));
	return (CODE_ERROR_INVALID_VALUE);
}

int	verify_operations(t_state *state)
{
	char	*line;
	int		res;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		res = parse_and_execute(state, line);
		free(line);
		if (res < 0)
			return (res);
	}
	res = is_stack_sorted(state->a, SORT_ASC);
	if (res < 0)
		return (res);
	else if (res == 1 && state->b->size == 0)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (CODE_OK);
}

int	main(int argc, char **argv)
{
	t_state	*state;
	int		res;

	if (argc <= 1)
		return (CODE_OK);
	state = state_init();
	if (!state)
	{
		ft_putendl_fd(STR_ERROR, STDERR_FILENO);
		return (CODE_ERROR_MALLOC);
	}
	res = parse_stack(state, argc, argv);
	if (res < 0)
	{
		state_del(state);
		ft_putendl_fd(STR_ERROR, STDERR_FILENO);
		return (res);
	}
	res = verify_operations(state);
	if (res < 0)
		ft_putendl_fd(STR_ERROR, STDERR_FILENO);
	state_del(state);
	return (res);
}
