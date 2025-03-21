/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_decor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:13:30 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 23:13:53 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"


void    load_wall_texture(t_map *game)
{
    int width;
    int height;

    game->textures.wall = mlx_xpm_file_to_image(game->mlx_connection,
        "./textures/wall/tree.xpm", &width, &height);
    if (!game->textures.wall)
    {
        ft_putendl_fd("Error loading wall texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
}

void    load_collectible_texture(t_map *game)
{
    int width;
    int height;

    game->textures.collectible = mlx_xpm_file_to_image(game->mlx_connection,
        "./textures/collectible/apple.xpm", &width, &height);
    if (!game->textures.collectible)
    {
        ft_putendl_fd("Error loading collectible texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
}

void    load_exit_texture(t_map *game)
{
    int width;
    int height;

    if (game->textures.exit)
        mlx_destroy_image(game->mlx_connection, game->textures.exit);
    if (game->collected != game->collectibles)
        game->textures.exit = mlx_xpm_file_to_image(game->mlx_connection,
            "./textures/exit/exit_closed.xpm", &width, &height);
    else
        game->textures.exit = mlx_xpm_file_to_image(game->mlx_connection,
            "./textures/exit/exit_open.xpm", &width, &height);
            
    if (!game->textures.exit)
    {
        ft_putendl_fd("Error loading exit texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
}

void    load_floor_texture(t_map *game)
{
    int width;
    int height;

    game->textures.floor = mlx_xpm_file_to_image(game->mlx_connection,
        "./textures/floor/grass.xpm", &width, &height);
    if (!game->textures.floor)
    {
        ft_putendl_fd("Error loading floor texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
}
