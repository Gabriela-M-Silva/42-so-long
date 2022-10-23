/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:05:31 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 10:11:35 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_direction(t_game *game, char direction)
{
	int	pixel;

	pixel = PIXEL;
	if (direction == 'l' && game->direction != 'l')
	{
		game->direction = 'l';
		mlx_destroy_image(game->mlx_ptr, game->images.cat_right);
		game->images.cat_left = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./images/cat_left.xpm", &pixel, &pixel);
	}
	else if (direction == 'r' && game->direction != 'r')
	{
		game->direction = 'r';
		mlx_destroy_image(game->mlx_ptr, game->images.cat_left);
		game->images.cat_right = mlx_xpm_file_to_image(game->mlx_ptr, \
			"./images/cat_right.xpm", &pixel, &pixel);
	}
}
