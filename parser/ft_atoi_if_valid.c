/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_if_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:48:26 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 13:48:28 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "utils.h"

int	is_number(char *str)
{
	char	*cursor;

	cursor = str;
	while (*cursor != '\0' && ft_isspace(*cursor))
		cursor++;
	if (*cursor == '-' || *cursor == '+')
		cursor++;
	if (!ft_isdigit(*cursor))
		return (0);
	while (*cursor != '\0' && ft_isdigit(*cursor))
		cursor++;
	if (*cursor != '\0')
		return (0);
	return (1);
}

void	init_ft_atoi_strict(int *nbr, int *nbr_prev, char **cursor, int *sign)
{
	*nbr = 0;
	*nbr_prev = 0;
	while (**cursor != '\0' && ft_isspace(**cursor))
		(*cursor)++;
	*sign = 1;
	if (**cursor == '+' || **cursor == '-')
	{
		if (**cursor == '-')
			*sign = -1;
		(*cursor)++;
	}
}

int	ft_atoi_strict(const char *str, int *ret)
{
	char	*cursor;
	int		nbr;
	int		nbr_prev;
	int		sign;

	cursor = (char *) str;
	init_ft_atoi_strict(&nbr, &nbr_prev, &cursor, &sign);
	while (*cursor != '\0' && ft_isdigit(*cursor))
	{
		nbr = nbr_prev * 10 + sign * ((int)(*cursor - '0'));
		if (sign == 1 && nbr < nbr_prev)
			return (CODE_ERROR_OUT_OF_RANGE_INT);
		if (sign == -1 && nbr > nbr_prev)
			return (CODE_ERROR_OUT_OF_RANGE_INT);
		nbr_prev = nbr;
		cursor++;
	}
	*ret = nbr;
	return (CODE_OK);
}

int	ft_atoi_if_valid(char *str, int *ret)
{
	if (!is_number(str))
		return (CODE_ERROR_NOT_A_NUMBER);
	return (ft_atoi_strict(str, ret));
}
