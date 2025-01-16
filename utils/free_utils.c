/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:47:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:34:19 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	clean_and_exit(t_map *map, char *line, int fd, int i)
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

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
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
	if (!data)
		return ;
	if (data->mlx_window && data->mlx_connection)
	{
		mlx_clear_window(data->mlx_connection, data->mlx_window);
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		data->mlx_window = NULL;
	}
	if (data->mlx_connection)
	{
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
		data->mlx_connection = NULL;
	}
}

int	close_window(t_map *game)
{
	clean_all_resources(game);
	exit(0);
}
