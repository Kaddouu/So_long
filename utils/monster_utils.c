/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 23:22:06 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/15 17:19:43 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static char	*create_frame_path(int frame_num)
{
	char	*num_str;
	char	*tmp;
	char	*frame_path;

	num_str = ft_itoa(frame_num);
	if (!num_str)
		return (NULL);
	tmp = ft_strjoin("./textures/monster/idle_down", num_str);
	free(num_str);
	if (!tmp)
		return (NULL);
	frame_path = ft_strjoin(tmp, ".xpm");
	free(tmp);
	if (!frame_path)
		return (NULL);
	return (frame_path);
}

void	clean_monster_frames(t_map *game, t_monster *monster)
{
	int	i;

	i = 0;
	while (i < MAX_FRAMES && monster->anim.frames[i])
	{
		mlx_destroy_image(game->mlx_connection, monster->anim.frames[i]);
		monster->anim.frames[i] = NULL;
		i++;
	}
}

int	load_monster_frames(t_map *game, t_monster *monster)
{
	char	*frame_path;
	int		i;
	int		width;
	int		height;

	i = 0;
	while (i < MAX_FRAMES)
	{
		frame_path = create_frame_path(i + 1);
		if (!frame_path || !validate_texture_file(frame_path))
		{
			ft_putstr_fd("Error\nMissing monster frame: ", 2);
			ft_putendl_fd(frame_path, 2);
			free(frame_path);
			close_window(game);
			return (0);
		}
		monster->anim.frames[i] = mlx_xpm_file_to_image(game->mlx_connection,
				frame_path, &width, &height);
		free(frame_path);
		if (!monster->anim.frames[i])
			return (0);
		i++;
	}
	return (1);
}
