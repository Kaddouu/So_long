/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:33:16 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/05 20:25:13 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <../minilibx-linux/mlx.h>
# include "../GNL/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>

# define TILE_SIZE 40

typedef struct s_textures {
    void    *player;
    void    *wall;
    void    *collectible;
    void    *exit;
    void    *floor;
}   t_textures;

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
    int     collectibles;
    int     collected;
    int     player;
    int     exit;
    int     moves;
    char    last_tile;
    void    *mlx_connection;
    void    *mlx_window;
    t_textures  textures;
}   t_map;

void    load_exit_texture(t_map *game);
t_map   *load_map(char *filename);
t_map   *load_map_content(t_map *map, char *filename);
int     process_map_line(t_map *map, char *line, int i);
int     check_walls(t_map *map);
void    count_elem(t_map *map);
int     check_map_validity(t_map *map);
int     flood_fill_check(t_map *map);
void    clean_and_exit(t_map *map, char *line, int fd, int i);
void    free_map(t_map *map);
void    free_mlx(t_map *data);
int     key_press(int key, t_map *data);
int     close_window(t_map *data);
int     render_game(t_map *game);

void    load_textures(t_map *game);
void    free_textures(t_map *game);
void    draw_tile(t_map *game, void *texture, int x, int y);
void    render_map(t_map *game);

#endif