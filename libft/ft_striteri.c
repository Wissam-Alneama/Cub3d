/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:37:18 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:50:19 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
