/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:08:15 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:14 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if ((char)c == str[i])
		{
			return (str + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return (str + i);
	}
	return (NULL);
}
