/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:54:06 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/23 16:08:12 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int	x;
	int	y;

	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &x, &y);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &x, &y);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"textures/collectable.xpm", &x, &y);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &x, &y);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &x, &y);
}
