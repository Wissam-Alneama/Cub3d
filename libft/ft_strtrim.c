/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:41:10 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:47 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	within(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && within(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && within(set, s1[end]))
		end--;
	len = end - start + 1;
	trim = malloc(len + 1);
	if (!trim)
		return (NULL);
	ft_memmove(trim, s1 + start, len);
	trim[len] = '\0';
	return (trim);
}
