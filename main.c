/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:10:13 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 12:27:43 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments. ");
		ft_printf("Please, choose one map.\n");
		ft_printf("Example: ./so_long ./maps/map.ber\n\n");
	}
	else
	{
		validate_map(argv[1], &game);
		handle_game(&game);
	}
	return (0);
}
