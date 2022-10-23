/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 06:23:51 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/15 00:51:47 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_chars(t_map *mp)
{
	mp->player = 0;
	mp->collectible = 0;
	mp->exit_map = 0;
}

void	count_required_chars(char c, t_game *game, int x, int y)
{
	if (c == 'P')
	{
		game->player.p_x = x;
		game->player.p_y = y;
		game->map.player++;
	}
	if (c == 'C')
		game->map.collectible++;
	if (c == 'E')
		game->map.exit_map++;
}

void	test_values(t_map *mp)
{
	if (mp->player != 1 || mp->exit_map != 1 || mp->collectible < 1)
	{
		ft_printf("Error\nInvalid number of map chars.\n\n");
		free_map(mp->map);
		exit(0);
	}
}

void	validate_chars(char **map, t_game *game)
{
	int		x;
	int		y;

	initialize_chars(&game->map);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E')
			{
				ft_printf("Error\nInvalid map chars.\n\n");
				free_map(map);
				exit(0);
			}
			count_required_chars(map[y][x], game, x, y);
		}
	}
	test_values(&game->map);
	game->map.height = y;
	game->map.width = ft_strlen(map[0]);
}
