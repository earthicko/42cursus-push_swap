/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:28:18 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:18 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "array.h"

void	print_array(t_array *array)
{
	int	i;

	printf("array len %d cap %d\n", array->len, array->cap);
	i = 0;
	while (i < array->len)
	{
		printf("[%d] ", array->data[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	t_array	*array;

	array = array_init(1);
	array_append(array, 1);
	print_array(array);
	array_append(array, 2);
	print_array(array);
	array_append(array, 3);
	print_array(array);
	return (0);
}
