/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:33:16 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/18 02:52:29 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../GNL/get_next_line.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <../minilibx-linux/mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 40
# define DIR_UP 1
# define DIR_LEFT 2
# define DIR_RIGHT 3
# define DIR_DOWN 4
# define MAX_FRAMES 6

typedef struct s_frame
{
	void			*frames[MAX_FRAMES];
	int				current_frame;
	int				frame_delay;
	int				delay_counter;
}					t_frame;

typedef struct s_player_anims
{
	t_frame			idle_up;
	t_frame			idle_down;
	t_frame			idle_left;
	t_frame			idle_right;
	t_frame			idle_down_exit;
	int				current_direction;
}					t_player_anims;

typedef struct s_monster
{
	int				x;
	int				y;
	int				move_delay;
	int				delay_counter;
	t_frame			anim;
}					t_monster;

typedef struct s_monster_list
{
	t_monster		*monsters;
	int				count;
}					t_monster_list;

typedef struct s_textures
{
	void			*player;
	void			*player_on_exit;
	void			*wall;
	void			*collectible;
	void			*exit;
	void			*floor;
	void			*monster;
}					t_textures;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	int				collectibles;
	int				collected;
	int				player;
	int				player_x;
	int				player_y;
	int				exit;
	int				moves;
	int				exit_x;
	int				exit_y;
	void			*mlx_connection;
	void			*mlx_window;
	t_player_anims	player_anims;
	t_textures		textures;
	t_monster_list	monsters;
	void		*counter_bg;
}					t_map;

/* ****************************************************************** */
/*                                                                    */
/*                      MAP INIT AND VALIDATION                       */
/*                                                                    */
/* ****************************************************************** */

t_map				*load_map(char *filename);
t_map				*load_map_content(t_map *map, char *filename);
int					count_map_height(t_map *map, char *filename,
						int empty_line_found);
int					allocate_map_array(t_map *map);
int					process_map_line(t_map *map, char *line, int i);
int					not_process_line(t_map *map, char *line, int i, int fd);
void				count_elem(t_map *map);
int					check_walls(t_map *map);
int					check_map_validity(t_map *map);
int					flood_fill_check(t_map *map);

/* ************************************************************************** */
/*                                                                            */
/*                         TEXTURE MANAGEMENT                                 */
/*                                                                            */
/* ************************************************************************** */

int					validate_texture_file(char *path);
void				*check_load_texture(t_map *game, char *path);
int					load_all_textures(t_map *game);
int					load_wall_texture(t_map *game);
int					load_collectible_texture(t_map *game);
int					load_floor_texture(t_map *game);
int					load_exit_texture(t_map *game);
void				load_player_direction_texture(t_map *game, char *path);
void				render_tile(t_map *game, int x, int y);
void				render_player(t_map *game, int x, int y);

/* ************************************************************************** */
/*                                                                            */
/*                       PLAYER ANIMATION HANDLING                            */
/*                                                                            */
/* ************************************************************************** */

void				init_frame(t_frame *frame);
int					init_animations(t_map *game);
void				update_animation(t_frame *frame);
t_frame				*get_current_anim(t_map *game);

/* ************************************************************************** */
/*                                                                            */
/*                         MONSTER MANAGEMENT                                 */
/*                                                                            */
/* ************************************************************************** */

int					init_monsters(t_map *game);
int					load_monster_frames(t_map *game, t_monster *monster);
void				update_all_monsters(t_map *game);
void				clean_monster_frames(t_map *game, t_monster *monster);

/* ************************************************************************** */
/*                                                                            */
/*                         PLAYER MOVEMENT                                    */
/*                                                                            */
/* ************************************************************************** */

void				move_up(t_map *game);
void				move_down(t_map *game);
void				move_left(t_map *game);
void				move_right(t_map *game);
void				find_player_pos(t_map *game, int *x, int *y);
int					can_move(t_map *game, int new_x, int new_y);
void				check_collision_and_collect(t_map *game, int new_x,
						int new_y);
void				handle_move(t_map *game, int new_x, int new_y);

/* ************************************************************************** */
/*                                                                            */
/*                         RENDERING                                          */
/*                                                                            */
/* ************************************************************************** */

int					render_game(t_map *game);
void				render_map(t_map *game);
void				render_monsters(t_map *game);
void				draw_tile(t_map *game, void *texture, int x, int y);

/* ************************************************************************** */
/*                                                                            */
/*                         EVENT HANDLING                                     */
/*                                                                            */
/* ************************************************************************** */

int					key_press(int key, t_map *data);
int					close_window(t_map *data);

/* ************************************************************************** */
/*                                                                            */
/*                         MEMORY MANAGEMENT                                  */
/*                                                                            */
/* ************************************************************************** */

void				free_map(t_map *map);
void				free_mlx(t_map *data);
void				free_textures(t_map *game);
void				free_monster_textures(t_map *game);
void				free_animation_frames(t_frame *frame, t_map *game);
void				clean_all_resources(t_map *game);
void				clean_remaining_lines(int fd);
void				clean_and_exit(t_map *map, char *line, int fd, int i);
int					clean_animations(t_map *game, int level);
void				free_and_close(t_map *map, int fd);
void	init_counter_bg(t_map *game);

#endif