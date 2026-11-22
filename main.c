/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42abui.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 07:31:34 by maryaada          #+#    #+#             */
/*   Updated: 2026/11/22 19:48:52 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./cub3D <map.cub>\n", 31);
		return (1);
	}
	ft_bzero(&g, sizeof(t_game));
	parse_file(&g, argv[1]);
	print_game_info(&g);
	init_window(&g);
	setup_hooks(&g);
	mlx_loop(g.mlx);
	free_game(&g);
	return (0);
}

void	print_game_info(t_game *g)
{
	int	y;

	printf("WE CAN USE PRINTF YAYAYAYAY\n");
	printf("NO:%s\nSO:%s\nWE:%s\nEA:%s\n",
		g->cfg.tex_path[0], g->cfg.tex_path[1],
		g->cfg.tex_path[2], g->cfg.tex_path[3]);
	printf("F:%06X C:%06X\n",
		g->cfg.floor_color, g->cfg.ceil_color);
	y = 0;
	while (g->map.grid[y])
		printf("|%s|\n", g->map.grid[y++]);
	printf("w=%d h=%d spawn=(%d,%d) %c\n",
		g->map.width, g->map.height,
		g->map.spawn_x, g->map.spawn_y,
		g->map.spawn_dir);
}
