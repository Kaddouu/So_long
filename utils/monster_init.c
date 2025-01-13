/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:38:29 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/13 14:41:03 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

static void count_monsters(t_map *game)
{
    int i = 0;
    int j;
    
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

static void init_monster_values(t_monster *monster, int x, int y)
{
    monster->x = x;
    monster->y = y;
    monster->move_delay = 300;
    monster->delay_counter = 0;
    monster->anim.current_frame = 0;
    monster->anim.frame_delay = 90;
    monster->anim.delay_counter = 0;
}

static int load_monster_frames(t_map *game, t_monster *monster)
{
    char *frame_path;
    char *tmp;
    char *num;
    int i = 0;
    int width, height;

    while (i < MAX_FRAMES)
    {
        num = ft_itoa(i + 1);
        if (!num)
            return (0);
        tmp = ft_strjoin("./textures/monster/idle_down", num);
        free(num);
        if (!tmp)
            return (0);
        frame_path = ft_strjoin(tmp, ".xpm");
        free(tmp);
        if (!frame_path)
            return (0);        
        int fd = open(frame_path, O_RDONLY);
        if (fd < 0)
        {
            ft_putendl_fd("Error: Monster texture file not found", 2);
            free(frame_path);
            return (0);
        }
        close(fd);
        monster->anim.frames[i] = mlx_xpm_file_to_image(
            game->mlx_connection, frame_path, &width, &height);
        free(frame_path);
        if (!monster->anim.frames[i])
            return (0);
        i++;
    }
    return (1);
}

static int init_single_monster(t_map *game, t_monster *monster, int x, int y)
{
    int i = 0;
    
    init_monster_values(monster, x, y);
    while (i < MAX_FRAMES)
    {
        monster->anim.frames[i] = NULL;
        i++;
    }
    if (!load_monster_frames(game, monster))
        return (0);
    return (1);
}

int init_monsters(t_map *game)
{
    int i;
	int	j;
	int monster_index = 0;

	i = -1;
    count_monsters(game);
    if (game->monsters.count == 0)
        return (1);

    game->monsters.monsters = malloc(sizeof(t_monster) * game->monsters.count);
    if (!game->monsters.monsters)
        return (0);

    while (++i < game->height)
    {
        j = -1;
        while (++j < game->width)
        {
            if (game->map[i][j] == 'M')
            {
                if (!init_single_monster(game, &game->monsters.monsters[monster_index], j, i))
                {
                    free_monster_textures(game);
                    return (0);
                }
                monster_index++;
            }
        }
    }
    return (1);
}
