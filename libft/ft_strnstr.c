/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:25:15 by walneama          #+#    #+#             */
/*   Updated: 2025/08/04 15:10:50 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	f;
	size_t	s;

	s = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[s] && s < len)
	{
		f = 0;
		while ((s + f < len) && (haystack[s + f] && needle[f])
			&& (haystack[s + f] == needle[f]))
		{
			f++;
			if (needle[f] == '\0')
			{
				return ((char *)haystack + s);
			}
		}
		s++;
	}
	return (NULL);
}
