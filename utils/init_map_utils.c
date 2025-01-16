/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:36:09 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:27:58 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	free_and_close(t_map *map, int fd)
{
	free(map);
	if (fd >= 0)
		close(fd);
}

int	count_map_height(t_map *map, char *filename, int empty_line_found)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n')
			empty_line_found = 1;
		else if (!empty_line_found)
			map->height++;
		free(line);
	}
	close(fd);
	if (empty_line_found)
	{
		ft_putendl_fd("Error\nEmpty line in map not allowed", 2);
		return (0);
	}
	return (map->height > 0);
}

int	allocate_map_array(t_map *map)
{
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (!(map->map))
		return (free(map), 0);
	return (1);
}

void	clean_remaining_lines(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			return ;
	}
}

int	not_process_line(t_map *map, char *line, int i, int fd)
{
	if (!process_map_line(map, line, i))
	{
		clean_and_exit(map, line, fd, i);
		clean_remaining_lines(fd);
		return (1);
	}
	free(line);
	return (0);
}
