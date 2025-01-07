/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:11:51 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/07 20:23:11 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_player_direction_texture(t_map *game, char *path)
{
    int width;
    int height;
	void	*new_texture;

	new_texture = mlx_xpm_file_to_image(game->mlx_connection, path, &width, &height);
    if (!new_texture)
    {
        ft_putendl_fd("Error loading player texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
	if (game->textures.player)
		mlx_destroy_image(game->mlx_connection, game->textures.player);
	game->textures.player = new_texture;
}

void    load_player_on_exit_texture(t_map *game)
{
    int width;
    int height;

    game->textures.player_on_exit = mlx_xpm_file_to_image(game->mlx_connection,
        "./textures/character/racoon_on_exit.xpm", &width, &height);
    if (!game->textures.player_on_exit)
    {
        ft_putendl_fd("Error loading player on exit texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
}
