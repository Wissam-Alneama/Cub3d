/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:19:02 by walneama          #+#    #+#             */
/*   Updated: 2026/11/14 16:20:47 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

static void	scan_row(t_game *g, char *row, int y, int *players)
{
	int	x;

	x = 0;
	while (row[x])
	{
		if (!ft_strchr(" 01NSEW", row[x]))
			error_exit(g, "Invalid character in map");
		if (ft_strchr("NSEW", row[x]))
		{
			(*players)++;
			g->map.spawn_x = x;
			g->map.spawn_y = y;
			g->map.spawn_dir = row[x];
		}
		x++;
	}
	if (x > g->map.width)
		g->map.width = x;
}

void	scan_map(t_game *g, int start, int last)
{
	int	players;
	int	i;

	players = 0;
	i = start;
	while (i <= last)
	{
		scan_row(g, g->lines[i], i - start, &players);
		i++;
	}
	if (players != 1)
		error_exit(g, "Map needs exactly one player start");
}

void	build_grid(t_game *g, int start)
{
	int	y;

	g->map.grid = ft_calloc(g->map.height + 1, sizeof(char *));
	if (!g->map.grid)
		error_exit(g, "Memory allocation failed");
	y = 0;
	while (y < g->map.height)
	{
		g->map.grid[y] = ft_calloc(g->map.width + 1, 1);
		if (!g->map.grid[y])
			error_exit(g, "Memory allocation failed");
		ft_memset(g->map.grid[y], ' ', g->map.width);
		ft_memcpy(g->map.grid[y], g->lines[start + y],
			ft_strlen(g->lines[start + y]));
		y++;
	}
	g->map.grid[g->map.spawn_y][g->map.spawn_x] = '0';
}
