/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:45:34 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 23:13:37 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void    load_textures(t_map *game)
{
    load_player_texture(game);
    load_wall_texture(game);
    load_collectible_texture(game);
    load_exit_texture(game);
    load_player_on_exit_texture(game);
    load_floor_texture(game);
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
            {
                if (x == game->exit_x && y == game->exit_y)
                    draw_tile(game, game->textures.player_on_exit, x, y);
                else
                    draw_tile(game, game->textures.player, x, y);
            }
            else if (game->map[y][x] == 'C')
                draw_tile(game, game->textures.collectible, x, y);
            else if (game->map[y][x] == 'E')
                draw_tile(game, game->textures.exit, x, y);
            x++;
        }
        y++;
    }
}
