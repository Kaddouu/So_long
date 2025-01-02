/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:33:16 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/02 22:36:42 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

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
}	t_map;

int check_walls(t_map *pos);
void count_elem(t_map *map);
int check_map_validity(t_map *map);
void clean_and_exit(t_map *map, char *line, int fd, int i);
void free_map(t_map *map);
t_map *init_map(void);
int process_map_line(t_map *map, char *line, int i);
t_map *load_map(char *filename);
t_map *load_map_content(t_map *map, char *filename);
void  flood_fill(char **tab, t_map size, t_map begin);







#endif