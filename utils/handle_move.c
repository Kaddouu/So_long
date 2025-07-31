/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:44:52 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/03/20 15:00:05 by ilkaddou         ###   ########.fr       */
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
			{
				game->player_x = *x;
				game->player_y = *y;
				return ;
			}
			(*x)++;
		}
		(*y)++;
	}
}

int	can_move(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E' && game->collected == game->collectibles)
	{
		ft_printf("Congratulations! You won in %d moves!\n", game->moves);
		close_window(game);
	}
	return (1);
}

static void	update_player_position(t_map *game, int new_x, int new_y,
		int on_exit)
{
	if (on_exit)
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	if (game->map[new_y][new_x] == 'E')
	{
		game->exit_x = new_x;
		game->exit_y = new_y;
	}
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
}

void	check_collision_and_collect(t_map *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'M')
	{
		ft_putendl_fd("Game Over! You ran into a monster!", 1);
		close_window(game);
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		ft_printf("Collectibles: %d/%d\n", game->collected, game->collectibles);
		if (game->collected == game->collectibles)
			load_exit_texture(game);
	}
}

void	handle_move(t_map *game, int new_x, int new_y)
{
	int	on_exit;

	on_exit = 0;
	if (!can_move(game, new_x, new_y))
		return ;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	if ((game->map[game->player_y][game->player_x] == 'P'
		&& (game->player_x == game->exit_x
			&& game->player_y == game->exit_y)))
		on_exit = 1;
	check_collision_and_collect(game, new_x, new_y);
	update_player_position(game, new_x, new_y, on_exit);
	render_map(game);
}
