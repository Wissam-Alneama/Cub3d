/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:03:00 by walneama          #+#    #+#             */
/*   Updated: 2026/11/14 14:15:28 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

static int	match(char *s, char *id)
{
	size_t	len;

	len = ft_strlen(id);
	return (ft_strncmp(s, id, len) == 0
		&& (is_ws(s[len]) || s[len] == '\0'));
}

static int	identify(char *s)
{
	if (match(s, "NO"))
		return (ID_NO);
	if (match(s, "SO"))
		return (ID_SO);
	if (match(s, "WE"))
		return (ID_WE);
	if (match(s, "EA"))
		return (ID_EA);
	if (match(s, "F"))
		return (ID_F);
	if (match(s, "C"))
		return (ID_C);
	return (-1);
}

static size_t	path_len(t_game *g, char *s)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	while (len > 0 && is_ws(s[len - 1]))
		len--;
	if (len == 0)
		error_exit(g, "Missing texture path");
	i = 0;
	while (i < len)
	{
		if (is_ws(s[i]))
			error_exit(g, "Extra characters after texture path");
		i++;
	}
	return (len);
}

static void	parse_texture(t_game *g, int id, char *s)
{
	size_t	len;
	int		fd;

	len = path_len(g, s);
	g->cfg.tex_path[id] = ft_substr(s, 0, len);
	if (!g->cfg.tex_path[id])
		error_exit(g, "Memory allocation failed");
	fd = open(g->cfg.tex_path[id], O_RDONLY);
	if (fd < 0)
		error_exit(g, "Cannot open texture file");
	close(fd);
}

void	parse_element(t_game *g, char *line)
{
	char	*s;
	int		id;

	s = skip_ws(line);
	id = identify(s);
	if (id < 0)
		error_exit(g, "Unknown or misplaced identifier");
	if (g->cfg.seen[id])
		error_exit(g, "Duplicate element");
	g->cfg.seen[id] = 1;
	if (id <= ID_EA)
		parse_texture(g, id, skip_ws(s + 2));
	else
		parse_color(g, id, skip_ws(s + 1));
}
