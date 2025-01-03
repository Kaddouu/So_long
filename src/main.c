/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:07:09 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/03 19:04:26 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    t_map *map;
    int i;
	void	*mlx;

	// mlx = mlx_init();
	// if (!mlx)
	// {
	// 	free(mlx);
	// 	return (1);
	// }

    i = 0;
    if (argc != 2)
        return (1);
    map = load_map(argv[1]);
    if (!map)
    {
        printf("Error: Failed to load map\n");
        return (1);
    }
	printf("\n\n");
    while (i < map->height)
    {
        printf("%s", map->map[i++]);
    }
	ft_putendl_fd("", 1);

    free_map(map);
    return (0);
}
