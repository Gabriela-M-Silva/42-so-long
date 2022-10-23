/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:11:49 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 13:47:59 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	check_read(char *str_map)
{
	if (!str_map)
	{
		ft_printf("Error\nEmpty map.\n\n");
		exit(0);
	}
}

char	*read_map(char *argv)
{
	char	*str_map;
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nMap file doesn't exist.\n\n");
		exit(0);
	}
	str_map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str_map = ft_strjoin_gnl(str_map, line);
		free(line);
	}
	check_read(str_map);
	return (str_map);
}

void	validate_map(char *argv, t_game *game)
{
	char	*str_map;

	validate_extension(argv);
	str_map = read_map(argv);
	game->map.map = ft_split(str_map, '\n');
	free(str_map);
	validate_rectangular(game->map.map);
	validate_walls(game->map.map);
	validate_chars(game->map.map, game);
	validate_path(argv, game);
}
