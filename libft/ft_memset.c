/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:17:04 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:05 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
