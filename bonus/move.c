/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:29:33 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 15:29:47 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	key_hooks(int key, t_data *win)
{
	int	c;

	c = win->moves;
	if (win->over)
		return (0);
	else if (key == KEY_W || key == KEY_UP)
		move_up(win);
	else if (key == KEY_S || key == KEY_DOWN)
		move_down(win);
	else if (key == KEY_A || key == KEY_LEFT)
		move_left(win);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_right(win);
	if (c != win->moves)
		ft_printf("Moves: %d\n", win->moves);
	return (0);
}

void	move_up(t_data *win)
{
	update_player(win, KEY_W);
	if (win->map[win->player_y - 1][win->player_x] != WALL &&
		(win->map[win->player_y - 1][win->player_x] != EXIT ||
			win->map_str->collect == 0))
	{
		if (win->map[win->player_y - 1][win->player_x] == COLLECTIBLE)
		{
			win->map_str->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y - 1][win->player_x] = PLAYER;
		}
		else if (win->map[win->player_y - 1][win->player_x] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y - 1][win->player_x] = PLAYER;
		}
		else if (win->map[win->player_y - 1][win->player_x] == ENEMY)
			win->over = 2;
		else
			win->over = 1;
		win->moves++;
		win->player_y--;
		mlx_clear_window(win->mlx_connection, win->mlx_window);
	}
	display_image(win, -1, -1);
}

void	move_down(t_data *win)
{
	update_player(win, KEY_DOWN);
	if (win->map[win->player_y + 1][win->player_x] != WALL &&
		(win->map[win->player_y + 1][win->player_x] != EXIT ||
			win->map_str->collect == 0))
	{
		if (win->map[win->player_y + 1][win->player_x] == COLLECTIBLE)
		{
			win->map_str->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y + 1][win->player_x] = PLAYER;
		}
		else if (win->map[win->player_y + 1][win->player_x] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y + 1][win->player_x] = PLAYER;
		}
		else if (win->map[win->player_y + 1][win->player_x] == ENEMY)
			win->over = 2;
		else
			win->over = 1;
		win->moves++;
		win->player_y++;
		mlx_clear_window(win->mlx_connection, win->mlx_window);
	}
	display_image(win, -1, -1);
}

void	move_left(t_data *win)
{
	update_player(win, KEY_LEFT);
	if (win->map[win->player_y][win->player_x - 1] != WALL &&
		(win->map[win->player_y][win->player_x - 1] != EXIT ||
			win->map_str->collect == 0))
	{
		if (win->map[win->player_y][win->player_x - 1] == COLLECTIBLE)
		{
			win->map_str->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x - 1] = PLAYER;
		}
		else if (win->map[win->player_y][win->player_x - 1] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x - 1] = PLAYER;
		}
		else if (win->map[win->player_y][win->player_x - 1] == ENEMY)
			win->over = 2;
		else
			win->over = 1;
		win->moves++;
		win->player_x--;
		mlx_clear_window(win->mlx_connection, win->mlx_window);
	}
	display_image(win, -1, -1);
}

void	move_right(t_data *win)
{
	update_player(win, KEY_RIGHT);
	if (win->map[win->player_y][win->player_x + 1] != WALL &&
		(win->map[win->player_y][win->player_x + 1] != EXIT ||
			win->map_str->collect == 0))
	{
		if (win->map[win->player_y][win->player_x + 1] == COLLECTIBLE)
		{
			win->map_str->collect--;
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x + 1] = PLAYER;
		}
		else if (win->map[win->player_y][win->player_x + 1] == FLOOR)
		{
			win->map[win->player_y][win->player_x] = FLOOR;
			win->map[win->player_y][win->player_x + 1] = PLAYER;
		}
		else if (win->map[win->player_y][win->player_x + 1] == ENEMY)
			win->over = 2;
		else
			win->over = 1;
		win->moves++;
		win->player_x++;
		mlx_clear_window(win->mlx_connection, win->mlx_window);
	}
	display_image(win, -1, -1);
}
