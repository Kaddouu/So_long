/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:16:48 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 23:17:20 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	move_up(t_map *game)
{
    int x;
    int y;

    find_player_pos(game, &x, &y);
    handle_move(game, x, y - 1);
}

void	move_down(t_map *game)
{
    int x;
    int y;

    find_player_pos(game, &x, &y);
    handle_move(game, x, y + 1);
}

void	move_left(t_map *game)
{
    int x;
    int y;

    find_player_pos(game, &x, &y);
    handle_move(game, x - 1, y);
}

void	move_right(t_map *game)
{
    int x;
    int y;

    find_player_pos(game, &x, &y);
    handle_move(game, x + 1, y);
}

int	key_press(int key, t_map *game)
{
    if (key == 65307) // ESC
    {
        printf("Game closed after %d moves\n", game->moves);
        close_window(game);
    }
    else if (key == 65362 || key == 119)
        move_up(game);
    else if (key == 65364 || key == 115)
        move_down(game);
    else if (key == 65361 || key == 97)
        move_left(game);
    else if (key == 65363 || key == 100)
        move_right(game);
    return (0);
}
