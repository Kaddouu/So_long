/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:47:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:33:24 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	validate_texture_file(char *path)
{
	int	fd;

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

void	*check_load_texture(t_map *game, char *path)
{
	void	*texture;
	int		width;
	int		height;

	if (!validate_texture_file(path))
	{
		ft_putstr_fd("Error\nMissing texture: ", 2);
		ft_putendl_fd(path, 2);
		return (NULL);
	}
	texture = mlx_xpm_file_to_image(game->mlx_connection, path, &width,
			&height);
	if (!texture)
	{
		ft_putstr_fd("Error\nInvalid texture: ", 2);
		ft_putendl_fd(path, 2);
		return (NULL);
	}
	return (texture);
}

void	clean_all_resources(t_map *game)
{
	if (!game)
		return ;
	if (game->monsters.monsters)
		free_monster_textures(game);
	free_textures(game);
	free_mlx(game);
	if (game->map)
		free_map(game);
}

void	free_textures(t_map *game)
{
	if (!game || !game->mlx_connection)
		return ;
	if (game->textures.player)
		mlx_destroy_image(game->mlx_connection, game->textures.player);
	if (game->textures.wall)
		mlx_destroy_image(game->mlx_connection, game->textures.wall);
	if (game->textures.collectible)
	{
		mlx_destroy_image(game->mlx_connection, game->textures.collectible);
	}
	if (game->textures.exit)
		mlx_destroy_image(game->mlx_connection, game->textures.exit);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx_connection, game->textures.floor);
	if (game->textures.player_on_exit)
		mlx_destroy_image(game->mlx_connection, game->textures.player_on_exit);
	game->textures = (t_textures){0};
	free_monster_textures(game);
	free_animation_frames(&game->player_anims.idle_up, game);
	free_animation_frames(&game->player_anims.idle_down, game);
	free_animation_frames(&game->player_anims.idle_left, game);
	free_animation_frames(&game->player_anims.idle_right, game);
	free_animation_frames(&game->player_anims.idle_down_exit, game);
}
