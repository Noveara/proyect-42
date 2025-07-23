/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:53:00 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/23 16:57:30 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

include "so_long.h"

void	find_player(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	flood_fill(char **map, int y, int x)
{
	int			collectable;

	collectable = 0;
	if (map[y][x] == 'E' || map[y][x] == 'C')
		collectable++;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return (collectable);
	}
	map[y][x] = '1';
	if (map[y - 1][x] != '1')
		collectable += flood_fill(map, y - 1, x);
	if (map[y + 1][x] != '1')
		collectable += flood_fill(map, y + 1, x);
	if (map[y][x - 1] != '1')
		collectable += flood_fill(map, y, x - 1);
	if (map[y][x + 1] != '1')
		collectable += flood_fill(map, y, x + 1);
	return (collectable);
}

bool	map_checker(t_game *game)
{
	char		**map2;
	int			reachables;

	map2 = ft_matrix_duplicate(game->map);
	find_player(map2, game);
	reachables = flood_fill(map2, game->player_y, game->player_x);
	ft_matrix_free(map2);
	if (reachables == game->collectables + 1)
		return (1);
	ft_printf("Error\n");
	return (0);
}
