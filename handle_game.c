/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 07:55:42 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 12:58:29 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!(game->mlx_ptr))
	{
		ft_printf("Error\nNo graphical interface.\n\n");
		free_map(game->map.map);
		exit(0);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.width * PIXEL, \
		game->map.height * PIXEL, "Long Luffy");
	game->moves = 0;
	game->direction = 'r';
}

void	create_images(t_game *game)
{
	int	pixel;

	pixel = PIXEL;
	game->images.grass = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/grass.xpm", &pixel, &pixel);
	game->images.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/wall.xpm", &pixel, &pixel);
	game->images.cat_right = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/cat_right.xpm", &pixel, &pixel);
	game->images.box = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/box.xpm", &pixel, &pixel);
	game->images.ball = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./images/ball.xpm", &pixel, &pixel);
}

void	free_game(t_game *game)
{
	if (game->direction == 'r')
		mlx_destroy_image(game->mlx_ptr, game->images.cat_right);
	else if (game->direction == 'l')
		mlx_destroy_image(game->mlx_ptr, game->images.cat_left);
	mlx_destroy_image(game->mlx_ptr, game->images.grass);
	mlx_destroy_image(game->mlx_ptr, game->images.wall);
	mlx_destroy_image(game->mlx_ptr, game->images.box);
	mlx_destroy_image(game->mlx_ptr, game->images.ball);
	free_map(game->map.map);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

void	handle_game(t_game *game)
{
	init_game(game);
	create_images(game);
	mlx_expose_hook(game->win_ptr, &handle_render, game);
	mlx_key_hook(game->win_ptr, &handle_key, game);
	mlx_hook(game->win_ptr, 17, 0, &handle_x, game);
	mlx_loop(game->mlx_ptr);
}
