/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:11:36 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:49:57 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pstr1;
	const unsigned char	*pstr2;
	size_t				i;

	pstr1 = (const unsigned char *)s1;
	pstr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (pstr1[i] != pstr2[i])
		{
			return (pstr1[i] - pstr2[i]);
		}
		i++;
	}
	return (0);
}
