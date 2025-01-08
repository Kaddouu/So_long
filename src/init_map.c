/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:14:14 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/08 16:31:56 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	init_map_values(t_map *map)
{
    // Initialisation des champs basiques
    map->height = 0;
    map->width = 0;
    map->collectibles = 0;
    map->collected = 0;
    map->moves = 0;
    map->exit_x = 0;
    map->exit_y = 0;
    
    // Initialisation des pointeurs MLX
    map->mlx_connection = NULL;
    map->mlx_window = NULL;
    
    // Initialisation des pointeurs de texture
    map->textures.player = NULL;
    map->textures.wall = NULL;
    map->textures.collectible = NULL;
    map->textures.exit = NULL;
    map->textures.floor = NULL;
    map->textures.player_on_exit = NULL;
}

t_map *load_map(char *filename)
{
    t_map *map = NULL;
    int fd;
    char *line;

    if (!ft_strnstr(filename, ".ber", ft_strlen(filename)))
        return (NULL);
    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    init_map_values(map);
    if ((fd = open(filename, O_RDONLY)) < 0)
    {
        free(map);
        return (NULL);
    }
    while ((line = get_next_line(fd)))
    {
        free(line);
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
    int		fd;
    char	*line;
    int 	i;
    char 	*tmp;

    i = 0;
    if ((fd = open(filename, O_RDONLY)) < 0)
        return (NULL);
    while ((line = get_next_line(fd)))
    {
        if (!process_map_line(map, line, i))
        {
            clean_and_exit(map, line, fd, i);
            close(fd);
            while ((tmp = get_next_line(fd)))
                free(tmp);
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
