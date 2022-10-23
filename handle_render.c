/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:20:49 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 12:58:53 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'P')
	{
		if (game->direction == 'r')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->images.cat_right, x * PIXEL, y * PIXEL);
		else if (game->direction == 'l')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
				game->images.cat_left, x * PIXEL, y * PIXEL);
	}
	if (game->map.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->images.box, x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->images.wall, x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->images.grass, x * PIXEL, y * PIXEL);
	if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->images.ball, x * PIXEL, y * PIXEL);
}

int	handle_render(t_game *game)
{
	int		x;
	int		y;
	char	*message;

	message = ft_itoa(game->moves);
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			render_map(game, x, y);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 4, 13, 0x0300, message);
	free(message);
	return (0);
}
