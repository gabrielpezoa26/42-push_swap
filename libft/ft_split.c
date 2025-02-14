/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:51:55 by gcesar-n          #+#    #+#             */
/*   Updated: 2025/02/13 22:54:13 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char delimiter)
{
	size_t	num;
	int		word;

	num = 0;
	word = 0;
	while (*s)
	{
		if (*s != delimiter && word == 0)
		{
			word = 1;
			num++;
		}
		else if (*s == delimiter)
			word = 0;
		s++;
	}
	return (num);
}

static void	*ft_free_memory(char **array, int free_position)
{
	while (free_position >= 0)
	{
		if (array[free_position])
			free(array[free_position]);
		free_position--;
	}
	free(array);
	return (NULL);
}

static int	ft_fillwords(char **result, char const *s, char c)
{
	size_t	len;
	int		word_index;

	word_index = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			result[word_index] = malloc(len + 1);
			if (!result[word_index])
				return (ft_free_memory(result, word_index - 1), -1);
			ft_strlcpy(result[word_index], s - len, len + 1);
			word_index++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (s == NULL)
		return (NULL);
	word_count = ft_countwords(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (ft_fillwords(result, s, c) == -1)
		return (ft_free_memory(result, word_count));
	result[word_count] = NULL;
	return (result);
}
