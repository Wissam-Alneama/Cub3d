/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42abui.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:46:04 by maryaada          #+#    #+#             */
/*   Updated: 2026/11/22 19:46:13 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	close_game(t_game *g)
{
	mlx_loop_end(g->mlx);
	return (0);
}

static int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
		mlx_loop_end(g->mlx);
	return (0);
}

void	setup_hooks(t_game *g)
{
	mlx_hook(g->win, 17, 1L << 17, close_game, g);
	mlx_hook(g->win, 2, 1L << 0, key_press, g);
	mlx_loop_hook(g->mlx, render, g);
}
