/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 05:39:55 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 12:59:38 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_extension(char *argv)
{
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".ber", 5) != 0)
	{
		ft_printf("Error\nInvalid map. Choose a .ber map.");
		ft_printf("\nExample: ./maps/map.ber\n\n");
		exit(0);
	}
}
