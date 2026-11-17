/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:17:09 by walneama          #+#    #+#             */
/*   Updated: 2026/11/14 16:18:16 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

static int	skip_blank(char **lines, int i)
{
	while (lines[i] && is_blank(lines[i]))
		i++;
	return (i);
}

static int	find_end(t_game *g, int start)
{
	int	i;
	int	last;

	i = start;
	last = start;
	while (g->lines[i])
	{
		if (!is_blank(g->lines[i]))
			last = i;
		i++;
	}
	i = start;
	while (i < last)
	{
		if (is_blank(g->lines[i]))
			error_exit(g, "Empty line inside the map");
		i++;
	}
	return (last);
}

void	parse_map(t_game *g, int i)
{
	int	start;
	int	last;

	start = skip_blank(g->lines, i);
	if (!g->lines[start])
		error_exit(g, "Missing map");
	last = find_end(g, start);
	g->map.height = last - start + 1;
	scan_map(g, start, last);
	build_grid(g, start);
}
