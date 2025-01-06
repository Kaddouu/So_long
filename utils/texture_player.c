/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:11:51 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/06 00:27:38 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	load_player_texture(t_map *game)
{
    int width;
    int height;

    game->textures.player = mlx_xpm_file_to_image(game->mlx_connection,
        "./textures/character/racoon2.xpm", &width, &height);
    if (!game->textures.player)
    {
        ft_putendl_fd("Error loading player texture", 2);
        free_textures(game);
        free_mlx(game);
        free_map(game);
        exit(1);
    }
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
