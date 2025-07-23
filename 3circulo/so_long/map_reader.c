/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:53:15 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/23 16:57:50 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_lines(char *map_name)
{
	int		fd;
	int		count_lines;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	count_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		count_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_lines);
}

char	*normalize_line(char *line)
{
	int		len;
	char	*new_line;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		return (line);
	new_line = malloc(len + 2);
	if (!new_line)
	{
		free(line);
		return (NULL);
	}
	ft_strlcpy(new_line, line, len + 1);
	new_line[len] = '\n';
	new_line[len + 1] = '\0';
	free(line);
	return (new_line);
}

void	fill_map(char *map_name, char **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		line = normalize_line(line);
		if (!line)
			exit(1);
		map[i] = ft_strdup(line);
		free(line);
		if (!map[i])
			exit(1);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
}

bool	map_reader(char *map_name, t_game *game)
{
	char	*route_map;
	int		count_lines;
	size_t	len;

	if (!(ft_strnstr(".ber", &map_name[ft_strlen(map_name) - 4], 4)))
		return (0);
	len = ft_strlen("maps/") + ft_strlen(map_name) + 1;
	route_map = malloc(len * sizeof(char));
	if (!route_map)
		return (0);
	route_map[0] = '\0';
	ft_strlcat(route_map, "maps/", len);
	ft_strlcat(route_map, map_name, len);
	count_lines = map_lines(route_map);
	if (count_lines == -1)
		return (free(route_map), 0);
	game->map = malloc((count_lines + 1) * sizeof(char *));
	if (!game->map)
		return (free(route_map), 0);
	fill_map(route_map, game->map);
	free(route_map);
	return (1);
}
