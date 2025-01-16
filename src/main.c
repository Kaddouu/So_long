/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:07:09 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/16 19:36:35 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int argc, char **argv, char **env)
{
	t_map	*game;

	if (argc != 2)
		return (1);
	if (!env[0])
		return (1);
	game = load_map(argv[1]);
	if (!game)
	{
		ft_putendl_fd("Failed to load game\n", 2);
		return (1);
	}
	render_game(game);
	return (0);
}
