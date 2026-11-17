/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:28:39 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:49:59 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (source == 0 && dest == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
