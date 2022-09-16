#ifndef ARRAY_H
# define ARRAY_H
# include <stdlib.h>
# include "consts.h"
# include "libft.h"

typedef struct s_array
{
	int	cap;
	int	len;
	int	*data;
}	t_array;

t_array	*array_init(int init_cap);
void	array_del(t_array *this);
int		array_append(t_array *array, int item);
#endif
