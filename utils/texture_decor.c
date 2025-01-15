/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_decor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:13:30 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/15 17:06:22 by ilkaddou         ###   ########.fr       */
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

static void	*load_texture(t_map *game, char *path)
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
	texture = mlx_xpm_file_to_image(game->mlx_connection, path, &width, &height);
	if (!texture)
	{
		ft_putstr_fd("Error\nInvalid texture: ", 2);
		ft_putendl_fd(path, 2);
		return (NULL);
	}
	return (texture);
}

int	load_wall_texture(t_map *game)
{
	game->textures.wall = load_texture(game, "./textures/wall/tree.xpm");
	if (!game->textures.wall)
		return (0);
	return (1);
}

int	load_collectible_texture(t_map *game)
{
	game->textures.collectible = load_texture(game,
			"./textures/collectible/apple.xpm");
	if (!game->textures.collectible)
		return (0);
	return (1);
}

int	load_floor_texture(t_map *game)
{
	game->textures.floor = load_texture(game, "./textures/floor/grass.xpm");
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
	game->textures.exit = load_texture(game, path);
	if (!game->textures.exit)
		return (0);
	return (1);
}

int	load_textures(t_map *game)
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
