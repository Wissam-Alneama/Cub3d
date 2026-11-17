/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:24:52 by walneama          #+#    #+#             */
/*   Updated: 2025/08/03 22:49:11 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_flow(long long number, int sign, char c)
{
	if (number > LLONG_MAX / 10
		|| (number == LLONG_MAX / 10 && (c - '0') > LLONG_MAX % 10))
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	number;
	int			sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (check_flow(number, sign, str[i]) != 1)
			return (check_flow(number, sign, str[i]));
		number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (sign * number);
}
