/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:36:47 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:12 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int	within;
	int	wordcounts;
	int	i;

	i = 0;
	wordcounts = 0;
	within = 0;
	while (s[i])
	{
		if (s[i] != c && within == 0)
		{
			wordcounts++;
			within = 1;
		}
		else if (s[i] == c)
			within = 0;
		i++;
	}
	return (wordcounts);
}

static char	*bring_word(const char *s, char c, int start, int *end_ptr)
{
	int	end;

	end = start;
	while (s[end] && s[end] != c)
		end++;
	*end_ptr = end;
	return (ft_substr(s, start, (end - start)));
}

static void	free_word(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free (array[i++]);
	free (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		arr;
	int		i;
	int		start;

	i = 0;
	arr = 0;
	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!array)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			array[arr] = bring_word(s, c, start, &i);
			if (!array[arr++])
				return (free_word(array), NULL);
		}
		else
			i++;
	}
	return (array[arr] = NULL, array);
}
