/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42abui.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:35:07 by maryaada          #+#    #+#             */
/*   Updated: 2026/11/22 19:46:16 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_window(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		error_exit(g, "mlx_init failed");
	g->win = mlx_new_window(g->mlx, WIN_W, WIN_H, "cub3D");
	if (!g->win)
		error_exit(g, "Error creating window!");
	g->frame.ptr = mlx_new_image(g->mlx, WIN_W, WIN_H);
	if (!g->frame.ptr)
		error_exit(g, "Error creating image!");
	g->frame.addr = mlx_get_data_addr(g->frame.ptr, &g->frame.bpp,
			&g->frame.line_len, &g->frame.endian);
	g->frame.width = WIN_W;
	g->frame.height = WIN_H;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}
