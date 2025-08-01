/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:56:20 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/18 01:37:10 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	check_valid_chars(char *line)
{
	int	j;

	j = -1;
	while (line[++j] && line[j] != '\n')
	{
		if (line[j] != '0' && line[j] != '1' && line[j] != 'C' && line[j] != 'E'
			&& line[j] != 'P' && line[j] != 'M')
		{
			ft_putendl_fd("Error\nOnly M, C, E, P, 0 and 1 are accepted.", 2);
			return (0);
		}
	}
	return (1);
}

int	process_map_line(t_map *map, char *line, int i)
{
	size_t	line_len;

	if (!line)
		return (0);
	line_len = ft_strlen(line);
	if (line[0] == '\n')
	{
		ft_putendl_fd("Error\nEmpty line in map not allowed", 2);
		return (0);
	}
	if (line[line_len - 1] == '\n')
		line_len--;
	if (i == 0)
		map->width = line_len;
	if (line_len != (size_t)map->width)
	{
		ft_putendl_fd("Error\nNot a rectangle", 2);
		return (0);
	}
	if (!check_valid_chars(line))
		return (0);
	map->map[i] = ft_strdup(line);
	return (map->map[i] != NULL);
}

int	check_walls(t_map *pos)
{
	int	i;

	i = 0;
	while (i < pos->width)
	{
		if (pos->map[0][i] != '1' || pos->map[pos->height - 1][i] != '1')
		{
			ft_putendl_fd("Error\nWalls must be '1' only", 2);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < pos->height)
	{
		if (pos->map[i][0] != '1' || pos->map[i][pos->width - 1] != '1')
		{
			ft_putendl_fd("Error\nWalls must be '1' only", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	count_elem(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	map->collectibles = 0;
	map->player = 0;
	map->exit = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map[i][j] == 'C')
				map->collectibles++;
			if (map->map[i][j] == 'P')
				map->player++;
			if (map->map[i][j] == 'E')
			{
				map->exit++;
				map->exit_x = j;
				map->exit_y = i;
			}
		}
	}
}

int	check_map_validity(t_map *map)
{
	count_elem(map);
	if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
	{
		ft_putendl_fd("Error\nNumber of 'C', 'E' or 'P' not valid", 2);
		return (0);
	}
	if (!check_walls(map))
	{
		return (0);
	}
	if (!flood_fill_check(map))
	{
		return (0);
	}
	return (1);
}
