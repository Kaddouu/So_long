/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:40:13 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:24:30 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	render_monsters(t_map *game)
{
	int			i;
	t_monster	*monster;

	i = -1;
	while (++i < game->monsters.count)
	{
		monster = &game->monsters.monsters[i];
		draw_tile(game, monster->anim.frames[monster->anim.current_frame],
			monster->x, monster->y);
	}
}
