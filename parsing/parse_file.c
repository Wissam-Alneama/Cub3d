/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:13:00 by walneama          #+#    #+#             */
/*   Updated: 2026/11/16 10:41:12 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

static void	check_extension(t_game *g, char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len <= 4 || ft_strncmp(path + len - 4, ".cub", 4) != 0)
		error_exit(g, "Map file must have the .cub extension");

	// we can add this check:
	// path doesn't include / by checking that path[len - 5] is not '/'
}

static int	count_lines(char *path)
{
	int		fd;
	int		n;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	n = 0;
	line = get_next_line(fd);
	while (line)
	{
		n++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (n);
}

static void	read_lines(t_game *g, char *path)
{
	int	n;
	int	i;
	int	fd;

	n = count_lines(path);
	if (n <= 0)
		error_exit(g, "Cannot read map: missing, empty or a directory");
	g->lines = ft_calloc(n + 1, sizeof(char *));
	if (!g->lines)
		error_exit(g, "Memory allocation failed");
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_exit(g, "Cannot open map file");
	i = 0;
	while (i < n)
	{
		g->lines[i] = get_next_line(fd);
		if (!g->lines[i])
			break ;
		strip_eol(g->lines[i]);
		i++;
	}
	close(fd);
	if (i < n)
		error_exit(g, "Error while reading map file");
}

static void	parse_header(t_game *g, int *i)
{
	while (g->lines[*i] && !all_seen(&g->cfg))
	{
		if (!is_blank(g->lines[*i]))
			parse_element(g, g->lines[*i]);
		(*i)++;
	}
	if (!all_seen(&g->cfg))
		error_exit(g, "Missing element before the map");
}

void	parse_file(t_game *g, char *path)
{
	int	i;

	check_extension(g, path);
	read_lines(g, path);
	i = 0;
	parse_header(g, &i);
	parse_map(g, i);
	validate_map(g);
	free_tab(g->lines);
	g->lines = NULL;
}
