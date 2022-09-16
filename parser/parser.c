#include "parser.h"

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
	if (n_split == 1)
		res = array_append(arr, ft_atoi(arg_split[0]));
	else if (n_split > 1)
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

t_array	*parse_args(int argc, char **argv)
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
