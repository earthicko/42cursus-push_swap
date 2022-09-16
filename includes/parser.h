#ifndef PARSER_H
# define PARSER_H
# include "deque.h"
# include "array.h"

t_array	*parse_args(int argc, char **argv);
int		construct_stack(t_deque *stack, t_array *arr);

char	**ft_split_space(char const *s);
void	free_strs(char **strs);
int		ft_isspace(char c);
#endif
