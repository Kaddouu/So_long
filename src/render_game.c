/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:19:42 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/28 16:45:10 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	update_game(t_map *game)
{
	update_all_monsters(game);
	render_map(game);
	return (0);
}

int	render_game(t_map *game)
{
	if (!game)
	{
		return (1);
	}
	game->mlx_connection = mlx_init();
	if (!game->mlx_connection)
	{
		clean_all_resources(game);
		return (1);
	}
	game->mlx_window = mlx_new_window(game->mlx_connection, game->width
			* TILE_SIZE, game->height * TILE_SIZE, "so_long");
	if (!game->mlx_window || !init_animations(game) || !init_monsters(game)
		|| !load_all_textures(game))
	{
		clean_all_resources(game);
		return (1);
	}
	init_counter_bg(game);
	render_map(game);
	mlx_hook(game->mlx_window, 17, 0, close_window, game);
	mlx_hook(game->mlx_window, 2, 1L << 0, key_press, game);
	mlx_loop_hook(game->mlx_connection, update_game, game);
	mlx_loop(game->mlx_connection);
	return (0);
}
