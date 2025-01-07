/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:19:42 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/07 17:32:37 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	render_game(t_map *game)
{
    game->moves = 0;
    game->collected = 0;
    game->mlx_connection = mlx_init();
    if (!game->mlx_connection)
        return (1);
    game->mlx_window = mlx_new_window(game->mlx_connection,
        game->width * TILE_SIZE,
        game->height * TILE_SIZE,
        "So Long");
    if (!game->mlx_window)
    {
        mlx_destroy_display(game->mlx_connection);
        free(game->mlx_connection);
        return (1);
    }
    load_textures(game);
    render_map(game);
    mlx_hook(game->mlx_window, 17, 0, close_window, game);
    mlx_hook(game->mlx_window, 2, 1L<<0, key_press, game);
    mlx_loop(game->mlx_connection);
    return (0);
}
