/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:47:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/13 17:41:52 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	clean_and_exit(t_map *map, char *line, int fd, int i)
{
	if (map)
	{
		if (map->map)
		{
			while (i > 0)
			{
				if (map->map[--i])
					free(map->map[i]);
			}
			free(map->map);
		}
		free(map);
	}
	if (line)
		free(line);
	if (fd >= 0)
		close(fd);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->map)
	{
		while (i < map->height)
			free(map->map[i++]);
		free(map->map);
	}
	free(map);
}

void	free_mlx(t_map *data)
{
	if (!data)
		return ;
	if (data->mlx_window && data->mlx_connection)
	{
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
		data->mlx_window = NULL;
	}
	if (data->mlx_connection)
	{
#ifdef __linux__
		mlx_destroy_display(data->mlx_connection);
#endif
		free(data->mlx_connection);
		data->mlx_connection = NULL;
	}
}

void	free_monster_textures(t_map *game)
{
	int	i;
	int	j;

	if (!game || !game->monsters.monsters)
		return ;
	i = -1;
	while (++i < game->monsters.count)
	{
		j = -1;
		while (++j < MAX_FRAMES)
		{
			if (game->monsters.monsters[i].anim.frames[j])
				mlx_destroy_image(game->mlx_connection,
					game->monsters.monsters[i].anim.frames[j]);
		}
	}
	free(game->monsters.monsters);
	game->monsters.monsters = NULL;
}

int	close_window(t_map *data)
{
	free_textures(data);
	free_mlx(data);
	free_map(data);
	exit(0);
}

/* Libère les frames d'une animation */

void	free_animation_frames(t_frame *frame, t_map *game)
{
	int	i;

	i = 0;
	while (i < MAX_FRAMES)
	{
		if (frame->frames[i])
			mlx_destroy_image(game->mlx_connection, frame->frames[i]);
		i++;
	}
}
int	clean_animations(t_map *game, int level)
{
	if (!game)
		return (0);
	if (level >= 4)
		free_animation_frames(&game->player_anims.idle_right, game);
	if (level >= 3)
		free_animation_frames(&game->player_anims.idle_left, game);
	if (level >= 2)
		free_animation_frames(&game->player_anims.idle_up, game);
	if (level >= 1)
		free_animation_frames(&game->player_anims.idle_down, game);
	return (0);
}

/* Libère toutes les textures du jeu */
void    free_textures(t_map *game)
{
    if (!game)
        return ;
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
    if (game->textures.player_on_exit)
        mlx_destroy_image(game->mlx_connection, game->textures.player_on_exit);
    free_monster_textures(game);
    free_animation_frames(&game->player_anims.idle_up, game);
    free_animation_frames(&game->player_anims.idle_down, game);
    free_animation_frames(&game->player_anims.idle_left, game);
    free_animation_frames(&game->player_anims.idle_right, game);
    free_animation_frames(&game->player_anims.idle_down_exit, game);
}
