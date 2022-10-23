/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rectangular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:55:42 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/07 04:57:03 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_rectangular(char **map)
{
	size_t	len_line_one;
	int		i;

	len_line_one = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (len_line_one != ft_strlen(map[i]))
		{
			ft_printf("Error\nMap is not rectangular.\n\n");
			free_map(map);
			exit(0);
		}
		i++;
	}
}
