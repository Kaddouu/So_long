/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:44:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 20:33:16 by ilkaddou         ###   ########.fr       */
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

static void	find_player_pos(t_map *game, int *x, int *y)
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

static int	can_move(t_map *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == '1')
        return (0);
    // if (game->map[new_y][new_x] == 'E' && game->collected != game->collectibles)
    //     return (0);
    return (1);
}

static void    handle_move(t_map *game, int new_x, int new_y)
{
    int current_x;
    int current_y;

    find_player_pos(game, &current_x, &current_y);
    if (!can_move(game, new_x, new_y))
        return;
    game->moves++;
    printf("Moves: %d\n", game->moves);
    if (game->map[new_y][new_x] == 'C')
    {
        game->collected++;
        printf("Collectibles: %d/%d\n", game->collected, game->collectibles);
        load_exit_texture(game);
    }
    if (game->map[new_y][new_x] == 'E' && game->collected == game->collectibles)
    {
        printf("Congratulations! You won in %d moves!\n", game->moves);
        close_window(game);
    }
    game->map[current_y][current_x] = '0';
    game->map[new_y][new_x] = 'P';
    render_map(game);
}

static void	move_up(t_map *game)
{
    int x;
    int y;

    find_player_pos(game, &x, &y);
    handle_move(game, x, y - 1);
}

static void	move_down(t_map *game)
{
    int x;
    int y;

    find_player_pos(game, &x, &y);
    handle_move(game, x, y + 1);
}

static void	move_left(t_map *game)
{
    int x;
    int y;

    find_player_pos(game, &x, &y);
    handle_move(game, x - 1, y);
}

static void	move_right(t_map *game)
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