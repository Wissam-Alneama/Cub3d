/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 15:28:26 by walneama          #+#    #+#             */
/*   Updated: 2026/11/08 16:32:34 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	free_mlx(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g->tex[i].ptr)
			mlx_destroy_image(g->mlx, g->tex[i].ptr);
		i++;
	}
	if (g->frame.ptr)
		mlx_destroy_image(g->mlx, g->frame.ptr);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	g->mlx = NULL;
}

void	free_game(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(g->cfg.tex_path[i]);
		g->cfg.tex_path[i] = NULL;
		i++;
	}
	free_tab(g->map.grid);
	free_tab(g->lines);
	g->map.grid = NULL;
	g->lines = NULL;
	free_mlx(g);
}

void	error_exit(t_game *g, char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_game(g);
	exit(1);
}
