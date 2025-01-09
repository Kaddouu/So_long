/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:39:59 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/09 19:42:39 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

/* Initialise une structure d'animation */
static void	init_animation(t_frame *frame)
{
	int	i;

	i = 0;
	frame->current_frame = 0;
	frame->frame_delay = 10;
	frame->delay_counter = 0;
	while (i < MAX_FRAMES)
		frame->frames[i++] = NULL;
}

/* Charge les images XPM pour une animation donnée */
static int	set_frames_xpm(t_map *game, t_frame *frame, char *base_path)
{
	char	*tmp_path;
	char	*frame_path;
	int		i;
	int		width;
	int		height;

	i = 0;
	while (i < MAX_FRAMES)
	{
		tmp_path = ft_strjoin(base_path, ft_itoa(i + 1));
		if (!tmp_path)
			return (0);
		frame_path = ft_strjoin(tmp_path, ".xpm");
		free(tmp_path);
		if (!frame_path)
			return (0);
		frame->frames[i] = mlx_xpm_file_to_image(game->mlx_connection,
				frame_path, &width, &height);
		free(frame_path);
		if (!frame->frames[i++])
			return (0);
	}
	return (1);
}

int	init_player_animation(t_map *game)
{
	init_animation(&game->player_anims.idle_up);
	init_animation(&game->player_anims.idle_down);
	init_animation(&game->player_anims.idle_left);
	init_animation(&game->player_anims.idle_right);
	if (!set_frames_xpm(game, &game->player_anims.idle_up, ".textures/character/idle_up"))
		return (0);
	if (!set_frames_xpm(game, &game->player_anims.idle_down, ".textures/character/idle_down"))
		return (0);
	if (!set_frames_xpm(game, &game->player_anims.idle_left, ".textures/character/idle_left"))
		return (0);
	if (!set_frames_xpm(game, &game->player_anims.idle_right, ".textures/character/idle_right"))
		return (0);
	game->player_anims.current_direction = 4;
	return (1);
}

t_frame	*get_current_anim(t_map *game)
{
	if (game->player_anims.current_direction == DIR_UP)
		return (&game->player_anims.idle_up);
	if (game->player_anims.current_direction == DIR_LEFT)
		return (&game->player_anims.idle_left);
	if (game->player_anims.current_direction == DIR_RIGHT)
		return (&game->player_anims.idle_right);
	return (&game->player_anims.idle_down);
}

void	update_animation(t_frame *frame)
{
	frame->delay_counter++;
	if (frame->delay_counter >= frame->frame_delay)
	{
		frame->current_frame = (frame->current_frame + 1) % MAX_FRAMES;
		frame->delay_counter = 0;
	}
}



