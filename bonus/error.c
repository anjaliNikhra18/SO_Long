/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:29:01 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 17:00:13 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	error_message(int code)
{
	errno = code;
	if (code == 2)
		perror(FILE_ERROR);
	else if (code == 8)
		perror(FILE_NAME_ERROR);
	else if (code == 5)
		ft_printf(WIDTH_NOT_SAME);
	else if (code == 27)
		perror(MAP_SIZE_ISSUE);
	else if (code == 7)
		ft_printf(UNKNOWN_CHAR);
	else if (code == 18)
		ft_printf(FOUR_SIDE_WALL);
	else if (code == 9)
		ft_printf(CAN_NOT_COLLECT);
	else if (code == 10)
		ft_printf(EXIT_NOT_REACHABLE);
	else
	{
		errno = 5;
		perror(strerror(errno));
	}
	return (0);
}

int	check_errors(t_data *win)
{
	if (check_map_dimensions(win) && check_boundary_walls(win) && \
		count_components(win, -1, -1) && check_components(win))
	{
		if (check_path(win))
			return (1);
		else
		{
			exit_game_before_window(win);
			return (0);
		}
	}
	else
	{
		exit_game_before_window(win);
		return (0);
	}
}

int	check_path(t_data *win)
{
	int		i;
	char	**map_dup;

	win->to_collect = 0;
	win->to_exit = 0;
	map_dup = malloc(sizeof(char *) * (win->map_str->h + 1));
	if (!map_dup)
		return (0);
	i = -1;
	while (win->map[++i])
		map_dup[i] = ft_strdup(win->map[i]);
	map_dup[i] = NULL;
	check_move(map_dup, win->player_x, win->player_y, win);
	free_map(map_dup);
	if (win->to_collect != (win->map_str->collect))
		return (error_message(9));
	else if (win->to_exit != 1)
		return (error_message(10));
	else
		return (1);
}

void	check_move(char **map_dup, int x, int y, t_data *win)
{
	if (map_dup[y][x] == COLLECTIBLE)
		win->to_collect += 1;
	if (map_dup[y][x] == EXIT || map_dup[y][x] == ENEMY)
	{
		if (map_dup[y][x] == EXIT)
			win->to_exit += 1;
		map_dup[y][x] = WALL;
		return ;
	}
	map_dup[y][x] = FLAG;
	if (map_dup[y][x + 1] != WALL && map_dup[y][x + 1] !=
		FLAG && map_dup[y][x + 1])
		check_move(map_dup, x + 1, y, win);
	if (map_dup[y][x - 1] != WALL && map_dup[y][x - 1] !=
		FLAG && map_dup[y][x - 1])
		check_move(map_dup, x - 1, y, win);
	if (map_dup[y + 1][x] != WALL && map_dup[y + 1][x] !=
		FLAG && map_dup[y + 1][x])
		check_move(map_dup, x, y + 1, win);
	if (map_dup[y - 1][x] != WALL && map_dup[y - 1][x] !=
		FLAG && map_dup[y - 1][x])
		check_move(map_dup, x, y - 1, win);
}
