/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:38:29 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:23:07 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void	init_monster_frames(t_monster *monster)
{
	int	i;

	i = 0;
	while (i < MAX_FRAMES)
	{
		monster->anim.frames[i] = NULL;
		i++;
	}
}

static void	init_monster_values(t_monster *monster, int x, int y)
{
	monster->x = x;
	monster->y = y;
	monster->move_delay = 700;
	monster->delay_counter = 0;
	monster->anim.current_frame = 0;
	monster->anim.frame_delay = 90;
	monster->anim.delay_counter = 0;
	init_monster_frames(monster);
}

static void	count_monsters(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	game->monsters.count = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'M')
				game->monsters.count++;
			j++;
		}
		i++;
	}
}

static int	init_single_monster(t_map *game, t_monster *monster, int x, int y)
{
	init_monster_values(monster, x, y);
	if (!load_monster_frames(game, monster))
	{
		clean_monster_frames(game, monster);
		return (0);
	}
	return (1);
}

int	init_monsters(t_map *game)
{
	int	i;
	int	j;
	int	monster_index;

	i = -1;
	monster_index = 0;
	count_monsters(game);
	if (game->monsters.count == 0)
		return (1);
	game->monsters.monsters = ft_calloc(game->monsters.count,
			sizeof(t_monster));
	if (!game->monsters.monsters)
		return (0);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			if (game->map[i][j] == 'M')
				if (!init_single_monster(game,
						&game->monsters.monsters[monster_index++], j, i))
					return (free_monster_textures(game), 0);
	}
	return (1);
}
