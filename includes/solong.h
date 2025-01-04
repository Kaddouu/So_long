/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:33:16 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/04 20:20:23 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "X11/keysym.h" 
# define TILE_SIZE 80

typedef struct s_map
{
	char		**map;
	int		height;
	int		width;
	int		exit;	
	int		player;
	int		collectibles;
	int		x;
	int		y;
	void	*window;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*mlx_connection;
	void	*mlx_window;
}	t_map;

int 	check_walls(t_map *pos);
void 	count_elem(t_map *map);
int		check_map_validity(t_map *map);
int 	flood_fill_check(t_map *map);

void 	clean_and_exit(t_map *map, char *line, int fd, int i);
void 	free_map(t_map *map);
void	free_mlx(t_map *data);
int		close_window(t_map *data);

t_map 	*init_map(void);
int 	process_map_line(t_map *map, char *line, int i);
t_map 	*load_map(char *filename);
t_map 	*load_map_content(t_map *map, char *filename);

int		render_game(t_map *game);
int		key_press(int key, t_map *data);










#endif