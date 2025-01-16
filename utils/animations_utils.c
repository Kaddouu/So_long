/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:39:59 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:25:12 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	init_frame(t_frame *frame)
{
	int	i;

	i = 0;
	frame->current_frame = 0;
	frame->frame_delay = 120;
	frame->delay_counter = 0;
	while (i < MAX_FRAMES)
	{
		frame->frames[i] = NULL;
		i++;
	}
}

void	free_animation_frames(t_frame *frame, t_map *game)
{
	int	i;

	i = 0;
	while (i < MAX_FRAMES)
	{
		if (frame->frames[i])
			mlx_destroy_image(game->mlx_connection, frame->frames[i]);
		i++;
	}
}

int	clean_animations(t_map *game, int level)
{
	if (!game)
		return (0);
	if (level >= 4)
		free_animation_frames(&game->player_anims.idle_right, game);
	if (level >= 3)
		free_animation_frames(&game->player_anims.idle_left, game);
	if (level >= 2)
		free_animation_frames(&game->player_anims.idle_up, game);
	if (level >= 1)
		free_animation_frames(&game->player_anims.idle_down, game);
	return (0);
}
