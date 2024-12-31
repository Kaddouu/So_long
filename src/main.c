/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:07:09 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/12/31 00:59:54 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Toutes les fonctions précédentes ici...

int main(int argc, char **argv)
{
    t_map *map;
    int i;

    if (argc != 2)
    {
        printf("Usage: %s <map.ber>\n", argv[0]);
        return (1);
    }

    map = load_map(argv[1]);
    if (!map)
    {
        printf("Error: Failed to load map\n");
        return (1);
    }
    printf("Map loaded successfully!\n\n");
    printf("Dimensions: %dx%d\n", map->width, map->height);
    printf("Collectibles: %d\n", map->collectibles);
    printf("Players: %d\n", map->player);
    printf("Exits: %d\n", map->exit);
    printf("\nMap content:\n");
    i = 0;
    while (i < map->height)
    {
        printf("%s", map->map[i]);
        i++;
    }
    free_map(map);
    return (0);
}
