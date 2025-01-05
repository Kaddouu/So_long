/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:45:34 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 20:20:43 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void    load_player_texture(t_map *game)
{
    int width;
    int height;

    game->textures.player = mlx_xpm_file_to_image(game->mlx_connection,
        "./textures/character/racoon2.xpm", &width, &height);
    if (!game->textures.player)
    {
        ft_putendl_fd("Error loading player texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
}

static void    load_wall_texture(t_map *game)
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

static void    load_collectible_texture(t_map *game)
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

static void    load_floor_texture(t_map *game)
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

void    load_textures(t_map *game)
{
    load_player_texture(game);
    load_wall_texture(game);
    load_collectible_texture(game);
    load_exit_texture(game);
    load_floor_texture(game);
}

void    free_textures(t_map *game)
{
    if (game->textures.player)
        mlx_destroy_image(game->mlx_connection, game->textures.player);
    if (game->textures.wall)
        mlx_destroy_image(game->mlx_connection, game->textures.wall);
    if (game->textures.collectible)
        mlx_destroy_image(game->mlx_connection, game->textures.collectible);
    if (game->textures.exit)
        mlx_destroy_image(game->mlx_connection, game->textures.exit);
    if (game->textures.floor)
        mlx_destroy_image(game->mlx_connection, game->textures.floor);
}

void    draw_tile(t_map *game, void *texture, int x, int y)
{
    mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
        texture, x * TILE_SIZE, y * TILE_SIZE);
}

void    render_map(t_map *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            draw_tile(game, game->textures.floor, x, y);
            if (game->map[y][x] == '1')
                draw_tile(game, game->textures.wall, x, y);
            else if (game->map[y][x] == 'P')
                draw_tile(game, game->textures.player, x, y);
            else if (game->map[y][x] == 'C')
                draw_tile(game, game->textures.collectible, x, y);
            else if (game->map[y][x] == 'E')
                draw_tile(game, game->textures.exit, x, y);
            x++;
        }
        y++;
    }
}