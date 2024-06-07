/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:29:26 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 16:44:48 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	game_window(t_data *game)
{
	game->mlx_connection = mlx_init();
	if (NULL == game->mlx_connection)
		exit_game_after_window(game);
	game->mlx_window = mlx_new_window(game->mlx_connection,
			game->map_str->w * TILE_SIZE, game->map_str->h * \
				TILE_SIZE, "So Long");
	if (!game->mlx_window)
	{
		free(game->mlx_connection);
		exit_game_after_window(game);
	}
	game->moves = 0;
	game->over = 0;
	game->to_collect = game->map_str->collect;
	create_image(game);
	display_image(game, -1, -1);
}

void	create_image(t_data *game)
{
	game->relative_path = "textures/Floor/back.xpm";
	game->img->back = mlx_xpm_file_to_image(game->mlx_connection,
			game->relative_path, &game->img->img_w, &game->img->img_h);
	if (!game->img->back)
		printf("Failed to load wall image\n");
	game->img->wall = mlx_xpm_file_to_image(game->mlx_connection,
			"textures/Wall/Brick.xpm", &game->img->img_w, &game->img->img_h);
	if (!game->img->wall)
		printf("Failed to load wall image\n");
	game->img->collect = mlx_xpm_file_to_image(game->mlx_connection,
			"textures/Collectible/f.xpm", &game->img->img_w, &game->img->img_h);
	if (!game->img->collect)
		printf("Failed to load collectible image\n");
	game->img->enemy = mlx_xpm_file_to_image(game->mlx_connection,
			"textures/Enemy/E2.xpm", &game->img->img_w, &game->img->img_h);
	if (!game->img->enemy)
		printf("Failed to load enemy image\n");
	game->img->lock = mlx_xpm_file_to_image(game->mlx_connection,
			"textures/Exit/lock.xpm", &game->img->img_w, &game->img->img_h);
	if (!game->img->lock)
		printf("Failed to load lock image\n");
	game->img->exit = mlx_xpm_file_to_image(game->mlx_connection,
			"textures/Exit/exit.xpm", &game->img->img_w, &game->img->img_h);
	init_player(game);
	game->put_moves = NULL;
}

void	display_image(t_data *game, int i, int j)
{
	while (game->map[++j])
	{
		i = -1;
		while (game->map[j][++i])
		{
			mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
				game->img->back, i * TILE_SIZE, j * TILE_SIZE);
			if (game->map[j][i] == WALL)
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
					game->img->wall, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
					game->img->collect, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == ENEMY)
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
					game->img->enemy, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == PLAYER)
				mlx_put_image_to_window(game->mlx_connection, game->mlx_window,
					game->img->player, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == EXIT)
				display_exit(game, j, i);
		}
	}
	calculate_moves(game);
	game_status(game);
}

void	game_status(t_data *win)
{
	if (win->over == 1)
	{
		ft_printf(PLAYER_WON);
		ft_printf("-----------------------------------------------\n");
		ft_printf("|    🎉🎉🎉  Congratulations!!!!!  🎉🎉🎉     |\n");
		ft_printf("|    You found all collectibles and exit.     |\n");
		ft_printf("|        ✓✓✓✓✓✓✓✓ You won! ✓✓✓✓✓✓✓✓           |\n");
		ft_printf("-----------------------------------------------\n");
		exit_game_after_window(win);
	}
	else if (win->over == 2)
	{
		ft_printf(PLAYER_LOSE);
		ft_printf("-----------------------------------------------\n");
		ft_printf("|    😢😢😢  Sorry, You Lose!  😢😢😢         |\n");
		ft_printf("|    You were caught by the enemy.            |\n");
		ft_printf("|    Try again to win.                        |\n");
		ft_printf("-----------------------------------------------\n");
		exit_game_after_window(win);
	}
}
