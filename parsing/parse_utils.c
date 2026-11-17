/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 08:06:07 by walneama          #+#    #+#             */
/*   Updated: 2026/11/11 08:58:41 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

// is_ws, skip_ws, is_blank, all_seen

int	is_ws(char c)
{
	return (c == ' ' || c == '\t');
}

char	*skip_ws(char *s)
{
	while (is_ws(*s))
		s++;
	return (s);
}

int	is_blank(char *s)
{
	return (*skip_ws(s) == '\0');
}

int	all_seen(t_config *cfg)
{
	int	i;

	i = 0;
	while (i < ID_COUNT)
	{
		if (!cfg->seen[i])
			return (0);
		i++;
	}
	return (1);
}

void	strip_eol(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		len--;
	if (len > 0 && s[len - 1] == '\r')
		len--;
	s[len] = '\0';
}
