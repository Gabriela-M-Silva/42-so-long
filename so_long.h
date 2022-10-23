/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:07 by gde-mora          #+#    #+#             */
/*   Updated: 2022/10/17 13:50:34 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft/libft.h"
# include <fcntl.h>

# define KEY_ESCAPE (0xff1b)
# define PIXEL 80
# define KEY_UP (0x77)
# define KEY_DOWN (0x73)
# define KEY_RIGHT (0x64)
# define KEY_LEFT (0x61)

typedef struct s_map
{
	int		player;
	int		collectible;
	int		exit_map;
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_path
{
	int		collectible;
	int		exit_map;
	char	**aux;
}	t_path;

typedef struct s_images
{
	void	*grass;
	void	*cat_right;
	void	*cat_left;
	void	*ball;
	void	*box;
	void	*wall;
}	t_images;

typedef struct s_player
{
	int		p_x;
	int		p_y;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_images	images;
	int			moves;
	t_player	player;
	char		direction;
}	t_game;

void	validate_map(char *argv, t_game *game);
void	validate_extension(char *argv);
void	validate_rectangular(char **map);
void	free_map(char **map);
void	validate_walls(char **map);
void	validate_chars(char **map, t_game *game);
void	validate_path(char *argv, t_game *game);
char	*read_map(char *argv);
void	handle_game(t_game *game);
void	free_game(t_game *game);
int		handle_render(t_game *game);
int		handle_key(int key, t_game *game);
int		handle_x(t_game *game);
void	handle_moves(int key, t_game *game);
void	handle_direction(t_game *game, char direction);

#endif