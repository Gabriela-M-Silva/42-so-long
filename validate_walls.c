/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 02:19:27 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 12:57:57 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	validate_walls(char **map)
{
	int	i;
	int	j;
	int	last_line;
	int	last_column;

	last_line = count_lines(map) - 1;
	last_column = ft_strlen(map[0]) - 1;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[0][j] != '1' || map[i][0] != '1'
				|| map[i][last_column] != '1' || map[last_line][j] != '1')
			{
				ft_printf("Error\nInvalid walls.\n\n");
				free_map(map);
				exit(0);
			}
		}
	}
}
