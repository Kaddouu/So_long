/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:45:34 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/11 22:43:31 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_textures(t_map *game)
{
	if (!game)
		return ;
	load_floor_texture(game);
	load_wall_texture(game);
	load_collectible_texture(game);
	load_exit_texture(game);
}

void	draw_tile(t_map *game, void *texture, int x, int y)
{
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window, texture, x
		* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_map *game)
{
	int		x;
	int		y;
	t_frame	*current_anim;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == '0')
				draw_tile(game, game->textures.floor, x, y);
			else if (game->map[y][x] == '1')
				draw_tile(game, game->textures.wall, x, y);
			else if (game->map[y][x] == 'P')
			{
				update_animation(get_current_anim(game));
				current_anim = get_current_anim(game);
				draw_tile(game,
					current_anim->frames[current_anim->current_frame], x, y);
			}
			else if (game->map[y][x] == 'C')
				draw_tile(game, game->textures.collectible, x, y);
			else if (game->map[y][x] == 'E')
				draw_tile(game, game->textures.exit, x, y);
		}
	}
	render_monsters(game);
}