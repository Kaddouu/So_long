/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:07:09 by ilkaddou          #+#    #+#             */
/*   Updated: 2025/01/15 19:38:00 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	main(int argc, char **argv)
{
	t_map	*game;

	if (argc != 2)
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
