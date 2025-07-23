/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:02:25 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/23 16:56:16 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_exit(t_game *game)
{
	if (game)
	{
		if (game->map)
			ft_matrix_free(game->map);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_image(game->mlx, game->img_collectable);
		mlx_destroy_image(game->mlx, game->img_exit);
		mlx_destroy_image(game->mlx, game->img_floor);
		mlx_destroy_image(game->mlx, game->img_player);
		mlx_destroy_image(game->mlx, game->img_wall);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free(game);
	}
	exit(0);
}

void	map_main(char *map_name, t_game *game)
{
	if (map_reader(map_name, game) == 0)
	{
		ft_printf("Error\n");
		free (game);
		exit(1);
	}
	if (!map_validate(game))
	{
		ft_matrix_free(game->map);
		free(game);
		exit(1);
	}
	if (!map_checker(game))
	{
		ft_matrix_free(game->map);
		free(game);
		exit(1);
	}
}

void	mlx_main(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return ;
	game->win = mlx_new_window(game->mlx,
			game->width * 64, game->height * 64, "so_long");
	if (!game->win)
		return ;
	load_images(game);
	game_render(game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, handle_exit, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	game = malloc(sizeof(t_game));
	map_main(argv[1], game);
	mlx_main(game);
	return (0);
}
