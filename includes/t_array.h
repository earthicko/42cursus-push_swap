#ifndef T_ARRAY_H
# define T_ARRAY_H
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
int		array_append(t_array *array, int item);
#endif
