/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:11:41 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 15:20:01 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross(void *data)
{
	ft_printf(RED_CROSS_CLICKED);
	ft_printf("--------------------------------------------------\n");
	ft_printf("|              You gave up :(                    |\n");
	ft_printf("|   Is the game hard for you? Try again......    |\n");
	ft_printf("--------------------------------------------------\n");
	exit_game_after_window(data);
	return (0);
}

int	read_esc(int keysym, void *win)
{
	if (keysym == XK_Escape)
	{
		ft_printf(PRESSED_ESC);
		ft_printf("--------------------------------------------------\n");
		ft_printf("|              You gave up :(                    |\n");
		ft_printf("|   Is the game hard for you? Try again......    |\n");
		ft_printf("--------------------------------------------------\n");
		exit_game_after_window(win);
	}
	return (0);
}

int	exit_game_before_window(t_data *win)
{
	free_map(win->map);
	free(win->map_str);
	free(win->img);
	exit(0);
	return (0);
}

int	exit_game_after_window(t_data *data)
{
	mlx_clear_window(data->mlx_connection, data->mlx_window);
	mlx_destroy_image(data->mlx_connection, data->img->back);
	mlx_destroy_image(data->mlx_connection, data->img->wall);
	mlx_destroy_image(data->mlx_connection, data->img->collect);
	mlx_destroy_image(data->mlx_connection, data->img->lock);
	mlx_destroy_image(data->mlx_connection, data->img->player);
	mlx_destroy_image(data->mlx_connection, data->img->exit);
	mlx_destroy_window(data->mlx_connection, data->mlx_window);
	mlx_destroy_display(data->mlx_connection);
	free(data->mlx_connection);
	exit(0);
	return (0);
}

void	display_exit(t_data *win, int y, int x)
{
	if (win->map_str->collect != 0)
	{
		mlx_put_image_to_window(win->mlx_connection, win->mlx_window,
			win->img->exit, x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(win->mlx_connection, win->mlx_window,
			win->img->lock, x * TILE_SIZE, y * TILE_SIZE);
	}
	else
		mlx_put_image_to_window(win->mlx_connection, win->mlx_window,
			win->img->exit, x * TILE_SIZE, y * TILE_SIZE);
}
