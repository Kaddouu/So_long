/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:07:09 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 23:04:35 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int main(int argc, char **argv)
{
    t_map *game;

    if (argc != 2)
        return (1);
    if (!(game = load_map(argv[1])))
    {
        printf("Error: Failed to load game\n");
        return (1);
    }
	render_game(game);
	free_textures(game);
    free_mlx(game);
    free_map(game);
	free(game);
    return (0);
}
