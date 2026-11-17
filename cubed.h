/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 07:31:29 by maryaada          #+#    #+#             */
/*   Updated: 2026/11/17 09:06:25 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
#define CUBED_H

#include <ctype.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <math.h>
# include "minilibx-linux/mlx.h" //miss me? 
# include <fcntl.h>
# include "libft.h"

typedef enum e_elem
{
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA,
	ID_F,
	ID_C,
	ID_COUNT
}	t_elem;

typedef struct s_config
{
	char	*tex_path[4];
	int		floor_color;
	int		ceil_color;
	int		seen[ID_COUNT];
}	t_config;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		spawn_x;
	int		spawn_y;
	char	spawn_dir;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	t_config	cfg;
	t_map		map;
	t_player	player;
	char		**lines;
	void		*mlx;
	void		*win;
}	t_game;

// error checking
void	free_tab(char **tab);
void	free_game(t_game *g);
void	error_exit(t_game *g, char *msg);

// parsing
void	parse_file(t_game *g, char *path);
void	parse_element(t_game *g, char *line);
void	parse_color(t_game *g, int id, char *s);
void	parse_map(t_game *g, int i);

// parsing utils
void	strip_eol(char *s);
int		is_ws(char c);
char	*skip_ws(char *s);
int		is_blank(char *s);
int		all_seen(t_config *cfg);
void	scan_map(t_game *g, int start, int last);
void	build_grid(t_game *g, int start);
void	validate_map(t_game *g);

void	print_game_info(t_game *g);
#endif