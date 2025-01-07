/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:44:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/07 16:40:52 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:14:44 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 19:37:26 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	find_player_pos(t_map *game, int *x, int *y)
{
    *y = 0;
    while (*y < game->height)
    {
        *x = 0;
        while (*x < game->width)
        {
            if (game->map[*y][*x] == 'P')
                return;
            (*x)++;
        }
        (*y)++;
    }
}

int can_move(t_map *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == '1')
        return (0);
    if (game->map[new_y][new_x] == 'E' && game->collected == game->collectibles)
    {
        printf("Congratulations! You won in %d moves!\n", game->moves);
        close_window(game);
    }
    return (1);
}

void handle_move(t_map *game, int new_x, int new_y)
{
    int current_x;
    int current_y;
    int on_exit = 0;

    find_player_pos(game, &current_x, &current_y);
    if (!can_move(game, new_x, new_y))
        return;
    game->moves++;
    printf("Moves: %d\n", game->moves);
   if((game->map[current_y][current_x] == 'P' && 
        (current_x == game->exit_x && current_y == game->exit_y)))
     on_exit = 1;
    if (game->map[new_y][new_x] == 'C')
    {
        game->collected++;
        printf("Collectibles: %d/%d\n", game->collected, game->collectibles);
        if (game->collected == game->collectibles)
            load_exit_texture(game);
    }
    if (on_exit)
        game->map[current_y][current_x] = 'E';
    else
        game->map[current_y][current_x] = '0';
    if (game->map[new_y][new_x] == 'E')
    {
        game->exit_x = new_x;
        game->exit_y = new_y;
    }
    game->map[new_y][new_x] = 'P';
    render_map(game);
}
