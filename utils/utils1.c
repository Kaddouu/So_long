/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:47:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 19:53:11 by ilkaddou         ###   ########.fr       */
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
                    free(map->map[i]);
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

void	free_mlx(t_map *data)
{
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
	if (data->mlx_connection)
		mlx_destroy_display(data->mlx_connection);
	free(data->mlx_connection);
}

// int	key_press(int key, t_map *data)
// {
//     if (key == 65307)
//     {
// 		printf("The %d key (ESC) has been pressed\n\n", key);
// 		free_mlx(data);
// 		free_map(data);
// 		exit(1);
//     }
//     if (key == 65362 || key == 119)
//         ;
//     if (key == 65364 || key == 115)
//         printf("Flèche bas pressée\n");
//     if (key == 65361 || key == 97)
//         printf("Flèche gauche pressée\n");
//     if (key == 65363 || key == 100)
// 	{
//         printf("Flèche droite pressée\n");
// 	}
// 	return (0);
// }

int	close_window(t_map *data)
{
	free_mlx(data);
	free_map(data);
	exit(0);
}
