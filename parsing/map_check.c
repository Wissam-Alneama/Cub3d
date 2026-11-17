/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:28:08 by walneama          #+#    #+#             */
/*   Updated: 2026/11/14 16:31:12 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

static int	leaks(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || x >= m->width || y >= m->height)
		return (1);
	return (m->grid[y][x] == ' ');
}

static int	cell_leaks(t_map *m, int x, int y)
{
	return (leaks(m, x - 1, y) || leaks(m, x + 1, y)
		|| leaks(m, x, y - 1) || leaks(m, x, y + 1));
}

void	validate_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grid[y][x] == '0' && cell_leaks(&g->map, x, y))
				error_exit(g, "Map is not closed by walls");
			x++;
		}
		y++;
	}
}
