#include "t_array.h"

t_array	*array_init(int init_cap)
{
	t_array	*init;

	init = (t_array *)malloc(sizeof(t_array));
	if (!init)
		return (NULL);
	init->data = (int *)malloc(sizeof(int) * init_cap);
	if (!init->data)
	{
		free(init);
		return (NULL);
	}
	init->cap = init_cap;
	init->len = 0;
	return (init);
}

int	array_resize(t_array *this, int size)
{
	int	*new_data;

	if (size < this->len)
		return (CODE_ERROR_INVALID_VALUE);
	new_data = (int *)malloc(sizeof(int) * size);
	if (!new_data)
		return (CODE_ERROR_MALLOC);
	ft_memcpy(new_data, this->data, sizeof(int) * this->len);
	free(this->data);
	this->data = new_data;
	return (CODE_OK);
}

int	array_append(t_array *this, int item)
{
	int	res;

	if (this->cap == this->len)
	{
		res = array_resize(this, this->cap * 2);
		if (res < 0)
			return (res);
	}
	this->data[this->len] = item;
	this->len++;
	return (CODE_OK);
}
