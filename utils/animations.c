/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:39:59 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 20:16:12 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static char	*create_frame_path(char *base_path, int frame_num)
{
	char	*tmp_path;
	char	*frame_path;
	char	*num_str;

	num_str = ft_itoa(frame_num);
	if (!num_str)
		return (NULL);
	tmp_path = ft_strjoin(base_path, num_str);
	free(num_str);
	if (!tmp_path)
		return (NULL);
	frame_path = ft_strjoin(tmp_path, ".xpm");
	free(tmp_path);
	if (!frame_path)
		return (NULL);
	return (frame_path);
}

static int	load_frame_images(t_map *game, t_frame *frame, char *base_path)
{
	char	*frame_path;
	int		i;
	int		width;
	int		height;

	i = -1;
	while (++i < MAX_FRAMES)
	{
		frame_path = create_frame_path(base_path, i + 1);
		if (!validate_texture_file(frame_path))
		{
			ft_putstr_fd("Error\nMissing frame: ", 2);
			ft_putendl_fd(frame_path, 2);
			free(frame_path);
			close_window(game);
			return (0);
		}
		frame->frames[i] = mlx_xpm_file_to_image(game->mlx_connection,
				frame_path, &width, &height);
		free(frame_path);
		if (!frame->frames[i])
			return (0);
	}
	return (1);
}

int	init_animations(t_map *game)
{
	init_frame(&game->player_anims.idle_up);
	init_frame(&game->player_anims.idle_down);
	init_frame(&game->player_anims.idle_left);
	init_frame(&game->player_anims.idle_right);
	init_frame(&game->player_anims.idle_down_exit);
	if (!load_frame_images(game, &game->player_anims.idle_down,
			"./textures/character/idle_down"))
		return (0);
	if (!load_frame_images(game, &game->player_anims.idle_up,
			"./textures/character/idle_up"))
		return (clean_animations(game, 1), 0);
	if (!load_frame_images(game, &game->player_anims.idle_left,
			"./textures/character/idle_left"))
		return (clean_animations(game, 2), 0);
	if (!load_frame_images(game, &game->player_anims.idle_right,
			"./textures/character/idle_right"))
		return (clean_animations(game, 3), 0);
	if (!load_frame_images(game, &game->player_anims.idle_down_exit,
			"./textures/exit/on_exit"))
		return (clean_animations(game, 4), 0);
	game->player_anims.current_direction = DIR_DOWN;
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
