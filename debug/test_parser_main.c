/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:28:20 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/19 17:28:21 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"

int	main(int argc, char **argv)
{
	t_array	*arr;
	int		i;

	arr = parse_args(argc, argv);
	printf("Parsed %d args\n", arr->len);
	i = 0;
	while (i < arr->len)
	{
		printf("%d ", arr->data[i]);
		i++;
	}
	printf("\n");
	return (0);
}
