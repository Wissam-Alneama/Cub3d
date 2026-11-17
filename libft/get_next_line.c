/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:27:03 by walneama          #+#    #+#             */
/*   Updated: 2025/09/10 10:11:37 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	temp_it(char **str, char **holder)
{
	char	*temp;

	if (*holder)
	{
		temp = ft_strjoin(*holder, *str);
		free_wiss(holder);
		free_wiss (str);
		*str = temp;
	}
}

static char	*save_after_newline(char **str, char **rem, char **nonline)
{
	char	*ptr;
	char	*temp;

	ptr = ft_strchr(*str, '\n');
	if (ptr)
	{
		*rem = ft_strdup(ptr + 1);
		if (*rem && **rem == '\0')
			free_wiss(rem);
		*(ptr + 1) = '\0';
		temp_it(str, nonline);
		return (*str);
	}
	else
	{
		if (*nonline)
		{
			temp = ft_strjoin(*nonline, *str);
			free_wiss(nonline);
			*nonline = temp;
		}
		else
			*nonline = ft_strdup(*str);
	}
	return (NULL);
}

static int	check(char **str, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || fd >= OPEN_MAX)
		return (0);
	*str = malloc((size_t)BUFFER_SIZE + 1);
	if (!*str)
		return (0);
	return (1);
}

static char	*check_for_rem(char **nonline)
{
	char	*temp;

	if (*nonline)
	{
		temp = *nonline;
		*nonline = NULL;
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*str;
	char		*nonline;
	ssize_t		bread;

	bread = 1;
	nonline = NULL;
	if (!check (&str, fd))
		return (NULL);
	while (bread > 0)
	{
		bread = read(fd, str, BUFFER_SIZE);
		if (bread < 0)
			return (free_wiss (&str), free_wiss(&rem), NULL);
		str[bread] = '\0';
		if (bread == 0 && !nonline && !rem)
			return (free_wiss(&str), free_wiss(&rem), NULL);
		temp_it(&str, &rem);
		if (save_after_newline(&str, &rem, &nonline))
			return (str);
	}
	free_wiss(&str);
	return (check_for_rem(&nonline));
}
