/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:14:14 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/12/31 02:40:05 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"
#include "../GNL_github/get_next_line.h"

t_map *load_map(char *filename)
{
    t_map *map;
    int fd;
    char *line;

    if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
        return (NULL);
    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->height = 0;
    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        free(map);
        return (NULL);
    }
    while ((line = get_next_line(fd))) // Stocker la ligne dans une variable
    {
        free(line); // Libérer la mémoire de chaque ligne
        map->height++;
    }
    close(fd);
    map->map = malloc(sizeof(char *) * (map->height + 1));
    if (!(map->map))
    {
        free_map(map);
        return (NULL);
    }
    return (load_map_content(map, filename));
}

t_map *load_map_content(t_map *map, char *filename)
{
    int fd;
    char *line;
    int i;

    i = 0;
    if ((fd = open(filename, O_RDONLY)) < 0)
        return (NULL);
    while ((line = get_next_line(fd)))
    {
        if (!process_map_line(map, line, i))
        {
			clean_and_exit(map, line, fd, i);
            return (NULL);
        }
        free(line);
        i++;
    }
    close(fd);
    map->map[i] = NULL;
    if (!check_map_validity(map))
    {
        clean_and_exit(map, NULL, -1, i);
        return (NULL);
    }
    return (map);
}


