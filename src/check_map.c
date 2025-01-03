/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:56:20 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/03 18:37:05 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	process_map_line(t_map *map, char *line, int i)
{
	size_t	line_len;
	int		j;

	line_len = ft_strlen(line) - 1;
	if (i == 0)
		map->width = line_len;
	if (line_len != (size_t)map->width)
	{
		ft_putendl_fd("Not a rectangle\n", 2);
		return (0);
	}
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (line[j] != '0' && line[j] != '1' && line[j] != 'C'
		&& line[j] != 'E' && line[j] != 'P')
		{
			ft_putendl_fd("Only C, E, P, 0 and 1 are accepted.", 2);
			return (0);
		}
		j++;
	}
	if (!(map->map[i] = ft_strdup(line)))
		return (0);
	return (1);
}


int check_walls(t_map *pos)
{
    int i = 0;

    while (i < pos->width)
    {
        if (pos->map[0][i] != '1' || pos->map[pos->height - 1][i] != '1')
		{
			ft_putendl_fd("First and last row must be filled with '1' only", 2);
            return (1);
		}
        i++;
    }
    i = 0;
    while (i < pos->height)
    {
        if (pos->map[i][0] != '1' || pos->map[i][pos->width - 1] != '1')
		{
			ft_putendl_fd("First and last column must be filled with '1' only", 2);
            return (1);
		}
        i++;
    }
    return (0);
}

void count_elem(t_map *map)
{
    int i = 0;
    int j;
    map->collectibles = 0;
    map->player = 0;
    map->exit = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->map[i][j] == 'C')
                map->collectibles++;
            if (map->map[i][j] == 'P')
                map->player++;
            if (map->map[i][j] == 'E')
                map->exit++;
            j++;
        }
        i++;
    }
}
int check_map_validity(t_map *map)
{
    count_elem(map);
    if (map->collectibles < 1 || map->exit != 1 || map->player != 1)
	{
		ft_putendl_fd("Must contain at least one 'C', exactly one 'E' and one 'P'", 2);
        return (0);
	}
    if (check_walls(map))
	{
        return (0);
	}
	if (!flood_fill_check(map))
	{
		return (0);
	}
	return (1);
}

