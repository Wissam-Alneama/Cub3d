/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:17:55 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:45 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		length;

	str = (char *)s;
	length = 0;
	while (str[length])
	{
		length++;
	}
	if ((char)c == str[length])
	{
		return (str + length);
	}
	while (length > 0)
	{
		length--;
		if ((char)c == str[length])
		{
			return (str + length);
		}
	}
	return (NULL);
}
