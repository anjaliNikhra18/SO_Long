/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:25:32 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 18:23:08 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	game;

	errno = 22;
	if (ac == 2 && check_map_file(av[1]))
	{
		game.map = load_map(av[1]);
		game.map_str = malloc(sizeof(t_map));
		game.img = malloc(sizeof(t_img));
		if (!game.map_str || !game.img)
			return (error_message(MALLOC_ERROR));
		if (check_errors(&game))
		{
			game_window(&game);
			mlx_hook(game.mlx_window, 17, 0, red_cross, &game);
			mlx_key_hook(game.mlx_window, read_esc, &game);
			mlx_hook(game.mlx_window, 2, (1L << 0), &key_hooks, &game);
			mlx_loop_hook(game.mlx_window, render_next_frame, &game);
			mlx_loop(game.mlx_connection);
			exit_game_after_window(&game);
		}
	}
	else
		perror(strerror(errno));
	return (0);
}

int	render_next_frame(t_data *win)
{
	static size_t	t;

	update_enemy_n_collecible(win, t);
	t++;
	display_image(win, -1, -1);
	usleep(100000);
	return (0);
}
