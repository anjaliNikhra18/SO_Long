/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:27:49 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 15:09:50 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_data *win)
{
	if (win->map[win->player_y][win->player_x + 1] != WALL)
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_R.xpm", &win->img->img_w, &win->img->img_h);
	else if (win->map[win->player_y][win->player_x - 1] != WALL)
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_L.xpm", &win->img->img_w, &win->img->img_h);
	else if (win->map[win->player_y - 1][win->player_x] != WALL)
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_U.xpm", &win->img->img_w, &win->img->img_h);
	else
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_D.xpm", &win->img->img_w, &win->img->img_h);
}

void	check_exit_pos(t_data *win, int x, int y)
{
	if (win->map[y - 1][x] != WALL && win->map[y][x - 1] != WALL && \
		win->map[y + 1][x] == WALL && win->map[y][x + 1] == WALL)
		win->map_str->exit_pos = 1;
	else if (win->map[y - 1][x] == WALL && win->map[y][x - 1] != WALL && \
		win->map[y + 1][x] != WALL && win->map[y][x + 1] == WALL)
		win->map_str->exit_pos = 2;
	else if (win->map[y - 1][x] != WALL && win->map[y][x - 1] == WALL && \
		win->map[y + 1][x] == WALL && win->map[y][x + 1] != WALL)
		win->map_str->exit_pos = 3;
	else if (win->map[y - 1][x] == WALL && win->map[y][x - 1] == WALL && \
		win->map[y + 1][x] != WALL && win->map[y][x + 1] != WALL)
		win->map_str->exit_pos = 4;
	else if (win->map[y - 1][x] == WALL && win->map[y][x - 1] != WALL && \
		win->map[y + 1][x] != WALL && win->map[y][x + 1] != WALL)
		win->map_str->exit_pos = 5;
	else if (win->map[y - 1][x] != WALL && win->map[y][x - 1] == WALL && \
		win->map[y + 1][x] != WALL && win->map[y][x + 1] != WALL)
		win->map_str->exit_pos = 6;
	else if (win->map[y - 1][x] != WALL && win->map[y][x - 1] == WALL && \
		win->map[y + 1][x] != WALL && win->map[y][x + 1] == WALL)
		win->map_str->exit_pos = 14;
	else
		check_exit_pos1(win, x, y);
}

void	check_exit_pos1(t_data *win, int x, int y)
{
	if (win->map[y - 1][x] != WALL && win->map[y][x - 1] != WALL && \
		win->map[y + 1][x] == WALL && win->map[y][x + 1] != WALL)
		win->map_str->exit_pos = 7;
	else if (win->map[y - 1][x] != WALL && win->map[y][x - 1] != WALL && \
		win->map[y + 1][x] != WALL && win->map[y][x + 1] == WALL)
		win->map_str->exit_pos = 8;
	else if (win->map[y - 1][x] != WALL && win->map[y][x - 1] == WALL && \
		win->map[y + 1][x] == WALL && win->map[y][x + 1] == WALL)
		win->map_str->exit_pos = 9;
	else if (win->map[y - 1][x] == WALL && win->map[y][x - 1] != WALL && \
		win->map[y + 1][x] == WALL && win->map[y][x + 1] == WALL)
		win->map_str->exit_pos = 10;
	else if (win->map[y - 1][x] == WALL && win->map[y][x - 1] == WALL && \
		win->map[y + 1][x] != WALL && win->map[y][x + 1] == WALL)
		win->map_str->exit_pos = 11;
	else if (win->map[y - 1][x] == WALL && win->map[y][x - 1] == WALL && \
		win->map[y + 1][x] == WALL && win->map[y][x + 1] != WALL)
		win->map_str->exit_pos = 12;
	else if (win->map[y - 1][x] == WALL && win->map[y][x - 1] != WALL && \
		win->map[y + 1][x] == WALL && win->map[y][x + 1] != WALL)
		win->map_str->exit_pos = 13;
	else
		win->map_str->exit_pos = 15;
}

void	calculate_moves(t_data *win, int x, int y)
{
	char	*moves;
	char	*s;
	char	*c;
	char	*collected;

	s = ft_strdup("No. of Moves: ");
	moves = ft_itoa(win->moves);
	win->put_moves = ft_strjoin(s, moves);
	free(s);
	c = ft_strdup("Star Collected: ");
	collected = ft_itoa(win->to_collect - win->map_str->collect);
	win->put_collect = ft_strjoin(c, collected);
	free(c);
	mlx_string_put(win->mlx_connection, win->mlx_window, x + 10, \
					y + 20, 0xFFFFFF, win->put_moves);
	mlx_string_put(win->mlx_connection, win->mlx_window, x + 10, \
					y + 40, 0xFFFFFF, win->put_collect);
	free(win->put_moves);
	free(moves);
	free(collected);
}

void	update_player(t_data *win, int move)
{
	mlx_destroy_image(win->mlx_connection, win->img->player);
	if (move == KEY_RIGHT)
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_R.xpm", &win->img->img_w, &win->img->img_h);
	else if (move == KEY_LEFT)
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_L.xpm", &win->img->img_w, &win->img->img_h);
	else if (move == KEY_DOWN)
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_D.xpm", &win->img->img_w, &win->img->img_h);
	else if (move == KEY_UP)
		win->img->player = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Player/player_U.xpm", &win->img->img_w, &win->img->img_h);
}
