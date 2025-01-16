/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:39:44 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:24:22 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static int	is_valid_monster_move(t_map *game, int x, int y)
{
	return (game->map[y][x] != '1' && game->map[y][x] != 'E'
		&& game->map[y][x] != 'C' && game->map[y][x] != 'M');
}

static void	check_player_collision(t_map *game, int x, int y)
{
	int	player_x;
	int	player_y;

	find_player_pos(game, &player_x, &player_y);
	if (x == player_x && y == player_y)
	{
		ft_putendl_fd("Game Over! Monster got you!", 1);
		close_window(game);
	}
}

static void	move_monster(t_map *game, t_monster *monster, int new_x, int new_y)
{
	check_player_collision(game, new_x, new_y);
	game->map[monster->y][monster->x] = '0';
	game->map[new_y][new_x] = 'M';
	monster->x = new_x;
	monster->y = new_y;
}

static void	update_monster(t_map *game, t_monster *monster)
{
	const int	moves[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	int			valid_moves[4];
	int			valid_count;
	int			i;
	int			chosen_move;

	monster->delay_counter++;
	if (monster->delay_counter < monster->move_delay)
		return ;
	monster->delay_counter = 0;
	valid_count = 0;
	i = -1;
	while (++i < 4)
	{
		if (is_valid_monster_move(game, monster->x + moves[i][0], monster->y
			+ moves[i][1]))
			valid_moves[valid_count++] = i;
	}
	if (valid_count == 0)
		return ;
	chosen_move = valid_moves[rand() % valid_count];
	move_monster(game, monster, monster->x + moves[chosen_move][0], monster->y
		+ moves[chosen_move][1]);
}

void	update_all_monsters(t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->monsters.count)
	{
		update_monster(game, &game->monsters.monsters[i]);
		update_animation(&game->monsters.monsters[i].anim);
	}
}
