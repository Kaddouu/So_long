/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:14:14 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/17 20:05:37 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	init_map_values(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->collectibles = 0;
	map->collected = 0;
	map->moves = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->mlx_connection = NULL;
	map->mlx_window = NULL;
	map->textures.player = NULL;
	map->textures.wall = NULL;
	map->textures.collectible = NULL;
	map->textures.exit = NULL;
	map->textures.floor = NULL;
	map->textures.player_on_exit = NULL;
	map->monsters.monsters = NULL;
	map->monsters.count = 0;
}

static t_map	*init_new_map(char *filename)
{
	t_map	*map;

	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
	{
		ft_putendl_fd("Error\nNot a .ber file", 2);
		return (NULL);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map_values(map);
	return (map);
}

static t_map	*validate_map_size(t_map *map, char *filename)
{
	if (!count_map_height(map, filename, 0))
	{
		free_and_close(map, -1);
		return (NULL);
	}
	if (map->height == 0)
	{
		ft_putendl_fd("Error\nEmpty file", 2);
		free(map);
		return (NULL);
	}
	if (!allocate_map_array(map))
		return (NULL);
	return (map);
}

static t_map	*process_map_content(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (not_process_line(map, line, i, fd))
			return (NULL);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	if (i < map->height)
	{
		ft_putendl_fd("Error\nInvalid map format", 2);
		clean_and_exit(map, NULL, -1, i);
		return (NULL);
	}
	map->map[i] = NULL;
	return (map);
}

t_map	*load_map(char *filename)
{
	t_map	*map;
	int		fd;

	map = init_new_map(filename);
	if (!map)
		return (NULL);
	if (!validate_map_size(map, filename))
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map->map), free(map), NULL);
	map = process_map_content(map, fd);
	if (!map || !check_map_validity(map))
	{
		if (map)
			clean_and_exit(map, NULL, -1, map->height);
		return (NULL);
	}
	return (map);
}
