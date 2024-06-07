/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:57:40 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 18:21:20 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	game;

	errno = 22;
	if (ac == 2 && check_map_file(av[1]))
	{
		game.map = load_map(av[1]);
		if (!game.map)
			return (0);
		game.map_str = malloc(sizeof(t_map));
		game.img = (t_img *)malloc(sizeof(t_img));
		if (!game.map_str || !game.img)
			return (error_message(MALLOC_ERROR));
		if (check_errors(&game))
		{
			game_window(&game);
			mlx_hook(game.mlx_window, 17, 0, red_cross, &game);
			mlx_key_hook(game.mlx_window, read_esc, &game);
			mlx_hook(game.mlx_window, 2, (1L << 0), &key_hooks, &game);
			mlx_loop(game.mlx_connection);
			exit_game_after_window(&game);
		}
	}
	else
		perror(strerror(errno));
	return (0);
}
