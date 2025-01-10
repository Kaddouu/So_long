/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_directions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 23:16:48 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/10 01:00:18 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

// Détection du système d'exploitation
#ifdef _WIN32
# define KEY_ESC 27
# define KEY_UP 72
	// Vérifiez les valeurs spécifiques pour Windows si nécessaire
# define KEY_DOWN 80
# define KEY_LEFT 75
# define KEY_RIGHT 77
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
#elif __APPLE__
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
#elif __linux__
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
#else
# error "Unsupported operating system"
#endif

void	move_up(t_map *game)
{
	int	x;
	int	y;

	find_player_pos(game, &x, &y);
	handle_move(game, x, y - 1);
}

void	move_down(t_map *game)
{
	int	x;
	int	y;

	find_player_pos(game, &x, &y);
	handle_move(game, x, y + 1);
}

void	move_left(t_map *game)
{
	int	x;
	int	y;

	find_player_pos(game, &x, &y);
	handle_move(game, x - 1, y);
}

void	move_right(t_map *game)
{
	int	x;
	int	y;

	find_player_pos(game, &x, &y);
	handle_move(game, x + 1, y);
}

int	key_press(int key, t_map *game)
{
	if (key == KEY_ESC)
		close_window(game);
	else if (key == KEY_UP || key == KEY_W)
	{
		game->player_anims.current_direction = DIR_UP;
		move_up(game);
	}
	else if (key == KEY_LEFT || key == KEY_A)
	{
		game->player_anims.current_direction = DIR_LEFT;
		move_left(game);
	}
	else if (key == KEY_RIGHT || key == KEY_D)
	{
		game->player_anims.current_direction = DIR_RIGHT;
		move_right(game);
	}
	else if (key == KEY_DOWN || key == KEY_S)
	{
		game->player_anims.current_direction = DIR_DOWN;
		move_down(game);
	}
	return (0);
}
