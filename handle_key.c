/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 00:02:51 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/14 06:33:45 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int key, t_game *game)
{
	if (key == KEY_ESCAPE)
		free_game(game);
	else
		handle_moves(key, game);
	return (0);
}
