/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:54:42 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:03 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*dest;
	size_t			i;

	if (!dst && !src)
		return (dst);
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (source == dest || len == 0)
		return (dst);
	if (dest < source)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dest[len] = source[len];
	}
	return (dst);
}
