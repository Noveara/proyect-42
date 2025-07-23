/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:15:35 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/23 17:01:50 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <stdbool.h>

typedef struct s_game
{
	char	**map;

	void	*img_player;
	void	*img_floor;
	void	*img_wall;
	void	*img_exit;
	void	*img_collectable;

	void	*mlx;
	void	*win;

	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectables;
}	t_game;
/*Funciones de renderizado y eventos.*/
void	put_image(t_game *game, int i, int j);
void	game_render(t_game *game);
int		handle_exit(t_game *game);
void	map_main(char *map_name, t_game *game);
void	mlx_main(t_game *game);
int		main(int argc, char **argv);

/*Funciones relacionadas con el mapa.*/
void	find_player(char **map, t_game *game);
int		flood_fill(char **map, int y, int x);
bool	map_checker(t_game *game);
int		map_lines(char *map_name);
char	*normalize_line(char *line);
void	fill_map(char *map_name, char **map);
bool	map_reader(char *map_name, t_game *game);
bool	validate_square(char **map, t_game *game);
bool	validate_limits(t_game *game);
int		validate_chars(char **map, bool ini, bool exi, int collectables);
bool	map_validate(t_game *game);

/*Funciones relacionadas con los movimientos y teclas*/
int		player_moves(t_game *game, int new_y, int new_x);
int		handle_key(int keycode, t_game *game);

/* Funciones de inicialización de imágenes*/
void	load_images(t_game *game);
void	ft_matrix_free(char **matrix);

#endif