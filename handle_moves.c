/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:15:58 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 12:19:56 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map.map[game->player.p_y - 1][game->player.p_x] != '1')
	{
		if (game->map.map[game->player.p_y - 1][game->player.p_x] == 'E')
		{
			if (game->map.collectible == 0)
			{
				ft_printf("You win!\n");
				free_game(game);
			}
		}
		else
		{
			if (game->map.map[game->player.p_y - 1][game->player.p_x] == 'C')
				game->map.collectible--;
			game->moves++;
			game->map.map[game->player.p_y - 1][game->player.p_x] = 'P';
			game->map.map[game->player.p_y][game->player.p_x] = '0';
			game->player.p_y--;
			handle_render(game);
		}
	}
}

void	move_down(t_game *game)
{
	if (game->map.map[game->player.p_y + 1][game->player.p_x] != '1')
	{
		if (game->map.map[game->player.p_y + 1][game->player.p_x] == 'E')
		{
			if (game->map.collectible == 0)
			{
				ft_printf("You win!\n");
				free_game(game);
			}
		}
		else
		{
			if (game->map.map[game->player.p_y + 1][game->player.p_x] == 'C')
				game->map.collectible--;
			game->moves++;
			game->map.map[game->player.p_y + 1][game->player.p_x] = 'P';
			game->map.map[game->player.p_y][game->player.p_x] = '0';
			game->player.p_y++;
			handle_render(game);
		}
	}
}

void	move_right(t_game *game)
{
	handle_direction(game, 'r');
	if (game->map.map[game->player.p_y][game->player.p_x + 1] != '1')
	{
		if (game->map.map[game->player.p_y][game->player.p_x + 1] == 'E')
		{
			if (game->map.collectible == 0)
			{
				ft_printf("You win!\n");
				free_game(game);
			}
		}
		else
		{
			if (game->map.map[game->player.p_y][game->player.p_x + 1] == 'C')
				game->map.collectible--;
			game->moves++;
			game->map.map[game->player.p_y][game->player.p_x + 1] = 'P';
			game->map.map[game->player.p_y][game->player.p_x] = '0';
			game->player.p_x++;
		}
	}
	handle_render(game);
}

void	move_left(t_game *game)
{
	handle_direction(game, 'l');
	if (game->map.map[game->player.p_y][game->player.p_x - 1] != '1')
	{
		if (game->map.map[game->player.p_y][game->player.p_x - 1] == 'E')
		{
			if (game->map.collectible == 0)
			{
				ft_printf("You win!\n");
				free_game(game);
			}
		}
		else
		{
			if (game->map.map[game->player.p_y][game->player.p_x - 1] == 'C')
				game->map.collectible--;
			game->moves++;
			game->map.map[game->player.p_y][game->player.p_x - 1] = 'P';
			game->map.map[game->player.p_y][game->player.p_x] = '0';
			game->player.p_x--;
		}
	}
	handle_render(game);
}

void	handle_moves(int key, t_game *game)
{
	if (key == KEY_UP)
		move_up(game);
	else if (key == KEY_DOWN)
		move_down(game);
	else if (key == KEY_RIGHT)
		move_right(game);
	else if (key == KEY_LEFT)
		move_left(game);
}
