/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42abui.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:13:52 by maryaada          #+#    #+#             */
/*   Updated: 2026/11/22 20:15:13 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
//test render, opens window.

static void	fill_rows(t_game *g, int from, int to, int color)
{
	int	x;
	int	y;

	y = from;
	while (y < to)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(&g->frame, x, y, color);
			x++;
		}
		y++;
	}
}

int	render(t_game *g)
{
	fill_rows(g, 0, WIN_H / 2, g->cfg.ceil_color);
	fill_rows(g, WIN_H / 2, WIN_H, g->cfg.floor_color);
	mlx_put_image_to_window(g->mlx, g->win, g->frame.ptr, 0, 0);
	return (0);
}
