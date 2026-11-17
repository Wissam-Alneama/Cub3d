/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:07:35 by walneama          #+#    #+#             */
/*   Updated: 2025/08/04 11:51:29 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s) || len == 0)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start] && i < len)
	{
		sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}
