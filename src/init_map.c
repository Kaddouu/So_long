/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:14:14 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/15 20:04:58 by ilkaddou         ###   ########.fr       */
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

t_map	*load_map(char *filename)
{
	t_map	*map;

	map = NULL;
	if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
	{
		ft_putendl_fd("Error\nNot a .ber map", 2);
		return (NULL);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map_values(map);
	if (!count_map_height(map, filename))
	{
		free_and_close(map, -1);
		return (NULL);
	}
	if (map->height == 0)
	{
		ft_putendl_fd("Error\nEmpty file", 2);
		return (free(map), NULL);
	}
	if (!allocate_map_array(map))
		return (NULL);
	return (load_map_content(map, filename));
}

t_map	*load_map_content(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(map->map), free(map), NULL);
	while ((line = get_next_line(fd)))
	{
		if (not_process_line(map, line, i, fd))
			return (NULL);
		i++;
	}
	close(fd);
	if (i < map->height)
	{
		ft_putendl_fd("Error\nInvalid map format", 2);
		clean_and_exit(map, NULL, -1, i);
		return (NULL);
	}
	map->map[i] = NULL;
	if (!check_map_validity(map))
	{
		clean_and_exit(map, NULL, -1, i);
		return (NULL);
	}
	return (map);
}
