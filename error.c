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

void	free_game(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(g->cfg.tex_path[i]);
		i++;
	}
	free_tab(g->map.grid);
	free_tab(g->lines);
	g->map.grid = NULL;
	g->lines = NULL;
}

void	error_exit(t_game *g, char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	free_game(g);
	exit(1);
}