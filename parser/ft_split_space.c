/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:33:36 by donghyle          #+#    #+#             */
/*   Updated: 2022/09/17 03:33:37 by donghyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "parser.h"

static void	skip_separator(char **start, int inverted)
{
	if (inverted)
	{
		while (**start != '\0' && !ft_isspace(**start))
			(*start)++;
	}
	else
	{
		while (**start != '\0' && ft_isspace(**start))
			(*start)++;
	}
}

static int	count_words(char *str)
{
	int	n_words;

	n_words = 0;
	while (*str != '\0')
	{
		skip_separator(&str, 0);
		if (*str != '\0')
			n_words++;
		skip_separator(&str, 1);
	}
	return (n_words);
}

static char	*ft_strcpy_word(char *str)
{
	int		len_word;
	int		idx;
	char	*word;

	idx = 0;
	len_word = 0;
	while (str[len_word] != '\0' && !ft_isspace(str[len_word]))
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (idx < len_word)
	{
		word[idx] = str[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

static void	*abort_alloc(char **strs, int last_i)
{
	while (0 <= last_i)
	{
		free(strs[last_i]);
		last_i--;
	}
	free(strs);
	return (NULL);
}

char	**ft_split_space(char const *s)
{
	char	**strs;
	int		idx;
	int		n_words;
	char	*cursor;

	cursor = (char *)s;
	n_words = count_words(cursor);
	idx = 0;
	strs = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!strs)
		return (NULL);
	while (*cursor != '\0')
	{
		skip_separator(&cursor, 0);
		if (*cursor != '\0')
		{
			strs[idx] = ft_strcpy_word(cursor);
			if (!strs[idx])
				return (abort_alloc(strs, idx - 1));
			idx++;
		}
		skip_separator(&cursor, 1);
	}
	strs[idx] = NULL;
	return (strs);
}
