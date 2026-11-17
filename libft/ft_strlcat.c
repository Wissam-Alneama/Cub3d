/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:35:39 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:26 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	deslen;
	size_t	srclen;
	size_t	rem;
	size_t	i;

	i = 0;
	deslen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize == 0)
	{
		return (srclen);
	}
	if (dstsize <= deslen)
	{
		return (dstsize + srclen);
	}
	rem = dstsize - deslen - 1;
	while (src[i] && i < rem)
	{
		dst[deslen + i] = src[i];
		i++;
	}
	dst[deslen + i] = '\0';
	return (deslen + srclen);
}
