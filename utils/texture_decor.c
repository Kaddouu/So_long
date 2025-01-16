/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_decor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:13:30 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:33:19 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	load_wall_texture(t_map *game)
{
	game->textures.wall = check_load_texture(game, "./textures/wall/tree.xpm");
	if (!game->textures.wall)
		return (0);
	return (1);
}

int	load_collectible_texture(t_map *game)
{
	game->textures.collectible = check_load_texture(game,
			"./textures/collectible/apple.xpm");
	if (!game->textures.collectible)
		return (0);
	return (1);
}

int	load_floor_texture(t_map *game)
{
	game->textures.floor = check_load_texture(game,
			"./textures/floor/grass.xpm");
	if (!game->textures.floor)
		return (0);
	return (1);
}

int	load_exit_texture(t_map *game)
{
	char	*path;

	if (game->textures.exit)
	{
		mlx_destroy_image(game->mlx_connection, game->textures.exit);
		game->textures.exit = NULL;
	}
	if (game->collected != game->collectibles)
		path = "./textures/exit/exit_closed.xpm";
	else
		path = "./textures/exit/exit_open.xpm";
	game->textures.exit = check_load_texture(game, path);
	if (!game->textures.exit)
		return (0);
	return (1);
}

int	load_all_textures(t_map *game)
{
	if (!game || !game->mlx_connection)
		return (0);
	if (!load_floor_texture(game))
		close_window(game);
	if (!load_collectible_texture(game))
		close_window(game);
	if (!load_wall_texture(game))
		close_window(game);
	if (!load_exit_texture(game))
		close_window(game);
	return (1);
}
