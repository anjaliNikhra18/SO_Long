/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:57:27 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 18:07:47 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_dimensions(t_data *win)
{
	int	h;
	int	w;
	int	t;

	h = 0;
	t = -1;
	while (win->map[h])
	{
		w = 0;
		while (win->map[h][w])
		{
			w++;
		}
		if (t != -1 && t != w)
			return (error_message(5));
		t = w;
		h++;
	}
	if (h < MIN_MAP_HIEGHT || w < MIN_MAP_WIDTH || \
		h > MAX_MAP_HIEGHT || w > MAX_MAP_WIDTH)
		return (error_message(27));
	win->map_str->h = h;
	win->map_str->w = w;
	return (1);
}

int	check_boundary_walls(t_data *win)
{
	int	i;

	i = 0;
	while (i < win->map_str->w)
	{
		if (win->map[0][i] != WALL || win->map[win->map_str->h - 1][i] != WALL)
			return (error_message(18));
		i++;
	}
	i = 0;
	while (i < win->map_str->h)
	{
		if (win->map[i][0] != WALL || win->map[i][win->map_str->w - 1] != WALL)
			return (error_message(18));
		i++;
	}
	return (1);
}

int	count_components(t_data *win, int h, int w)
{
	win->map_str->player = 0;
	win->map_str->collect = 0;
	win->map_str->exit = 0;
	while (++w < win->map_str->w)
	{
		h = -1;
		while (++h < win->map_str->h)
		{
			if (win->map[h][w] == PLAYER)
			{
				win->map_str->player++;
				win->player_x = w;
				win->player_y = h;
			}
			else if (win->map[h][w] == COLLECTIBLE)
				win->map_str->collect++;
			else if (win->map[h][w] == EXIT)
				win->map_str->exit++;
		}
	}
	if (check_count_of_components(win))
		return (0);
	return (1);
}

int	check_count_of_components(t_data *win)
{
	int	t;

	t = 0;
	if (win->map_str->collect < 1)
	{
		ft_printf(ZERO_COLLECT);
		t = 1;
	}
	if (win->map_str->exit != 1)
	{
		ft_printf(ONE_EXIT);
		t = 1;
	}
	if (win->map_str->player != 1)
	{
		ft_printf(ONE_PLAYER);
		t = 1;
	}
	return (t);
}

int	check_components(t_data *win)
{
	int	h;
	int	w;

	if (!win->map)
		return (0);
	h = 0;
	while (win->map[h])
	{
		w = 0;
		while (win->map[h][w])
		{
			if (win->map[h][w] != PLAYER && win->map[h][w] != COLLECTIBLE
				&& win->map[h][w] != FLOOR && win->map[h][w] != EXIT \
					&& win->map[h][w] != WALL)
				return (error_message(7));
			if (win->map[h][w] == EXIT)
				check_exit_pos(win, w, h);
			w++;
		}
		h++;
	}
	return (1);
}
