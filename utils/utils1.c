/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:47:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/12/31 02:38:30 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void clean_and_exit(t_map *map, char *line, int fd, int i)
{
    if (map)
    {
        if (map->map)
        {
            while (i > 0)
            {
                if (map->map[--i])
            	{
					printf("Ligne %d sera free\n", i);
					printf("Ligne %s sera free\n\n", map->map[i]);
                    free(map->map[i]);
				} 	
            }
            free(map->map);
        }
        free(map);
	}
    if (line)
        free(line);
    if (fd >= 0)
		close(fd);                
}

void free_map(t_map *map)
{
    int i = 0;
    
    if (!map)
        return;
    if (map->map)
    {
        while (i < map->height)
            free(map->map[i++]);
        free(map->map);
    }
    free(map);
}