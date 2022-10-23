/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:16:17 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 13:49:47 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	substitute_position(t_path *valid_path, t_game *game, int y, int x)
{
	if (valid_path->aux[y][x] == '1')
		return ;
	else
	{
		if (valid_path->aux[y][x] == 'C')
			valid_path->collectible++;
		if (valid_path->aux[y][x] == 'E')
		{
			valid_path->exit_map++;
			if (valid_path->collectible != game->map.collectible)
				return ;
		}
		valid_path->aux[y][x] = '1';
		substitute_position(valid_path, game, y + 1, x);
		substitute_position(valid_path, game, y - 1, x);
		substitute_position(valid_path, game, y, x + 1);
		substitute_position(valid_path, game, y, x - 1);
		return ;
	}
}

void	validate_path(char *argv, t_game *game)
{
	t_path	valid_path;
	char	*str_aux;

	valid_path.collectible = 0;
	valid_path.exit_map = 0;
	str_aux = read_map(argv);
	valid_path.aux = ft_split(str_aux, '\n');
	free(str_aux);
	substitute_position(&valid_path, game, game->player.p_y, game->player.p_x);
	free_map(valid_path.aux);
	if (valid_path.collectible != game->map.collectible
		|| valid_path.exit_map != 1)
	{
		free_map(game->map.map);
		ft_printf("Error\nInvalid path.\n\n");
		exit(0);
	}
}
