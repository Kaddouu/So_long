/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:45:34 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/18 02:47:16 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void draw_tile(t_map *game, void *texture, int x, int y)
{
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window, texture, x * TILE_SIZE, y * TILE_SIZE);
}

void init_counter_bg(t_map *game)
{
	int x;
	int y;
	int width;
	int height;
	int *data;

	width = 120;
	height = 30;
	game->counter_bg = mlx_new_image(game->mlx_connection, width, height);
	if (!game->counter_bg)
		return;
	data = (int *)mlx_get_data_addr(game->counter_bg, &(int){0}, &(int){0}, &(int){0});
	if (!data)
		return;
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			data[y * width + x] = 0x000000;
		}
	}
}

static void put_count_moves(t_map *game)
{
	char *string;
	char *count;

	count = ft_itoa(game->moves);
	if (!count)
		return;
	string = ft_strjoin(count, " moves done.");
	if (!string)
		return;
	mlx_put_image_to_window(game->mlx_connection, game->mlx_window, game->counter_bg, 0, 0);
	mlx_string_put(game->mlx_connection, game->mlx_window, 10, 15, 0xFFFFFF, string);
	return (free(count), free(string));
}

void render_map(t_map *game)
{
	int x;
	int y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			render_tile(game, x, y);
		}
	}
	render_monsters(game);
	put_count_moves(game);
}

void render_tile(t_map *game, int x, int y)
{
	if (game->map[y][x] == '0')
		draw_tile(game, game->textures.floor, x, y);
	else if (game->map[y][x] == '1')
		draw_tile(game, game->textures.wall, x, y);
	else if (game->map[y][x] == 'P')
		render_player(game, x, y);
	else if (game->map[y][x] == 'C')
		draw_tile(game, game->textures.collectible, x, y);
	else if (game->map[y][x] == 'E')
		draw_tile(game, game->textures.exit, x, y);
}

void render_player(t_map *game, int x, int y)
{
	t_frame *current_anim;

	if (x == game->exit_x && y == game->exit_y && game->collected != game->collectibles)
	{
		update_animation(&game->player_anims.idle_down_exit);
		current_anim = &game->player_anims.idle_down_exit;
	}
	else
	{
		update_animation(get_current_anim(game));
		current_anim = get_current_anim(game);
	}
	draw_tile(game, current_anim->frames[current_anim->current_frame], x, y);
}
