/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walneama <walneama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:00:03 by walneama          #+#    #+#             */
/*   Updated: 2026/11/14 12:15:02 by walneama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

// read_component, set_color, parse_color

static char	*read_component(t_game *g, char *s, int *out)
{
	int	val;
	int	digits;

	val = 0;
	digits = 0;
	while (ft_isdigit(*s))
	{
		val = val * 10 + (*s - '0');
		if (val > 255)
			error_exit(g, "Color value out of range [0,255]");
		digits++;
		s++;
	}
	if (digits == 0)
		error_exit(g, "Invalid color value");
	*out = val;
	return (s);
}

static void	set_color(t_game *g, int id, int rgb[3])
{
	int	color;

	color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	if (id == ID_F)
		g->cfg.floor_color = color;
	else
		g->cfg.ceil_color = color;
}

void	parse_color(t_game *g, int id, char *s)
{
	int	rgb[3];
	int	i;

	i = 0;
	while (i < 3)
	{
		s = read_component(g, s, &rgb[i]);
		if (i < 2)
		{
			if (*s != ',')
				error_exit(g, "Color must be R,G,B");
			s++;
		}
		i++;
	}
	if (!is_blank(s))
		error_exit(g, "Extra characters after color");
	set_color(g, id, rgb);
}