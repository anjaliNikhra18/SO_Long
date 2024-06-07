/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:58:04 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 15:01:24 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>

# define MALLOC_ERROR 1
# define MLX_ERROR 1
# define WIDTH 500
# define HEIGHT 500

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define TILE_SIZE 64

# define PLAYER 80
# define WALL 49
# define COLLECTIBLE 67
# define EXIT 69
# define FLOOR 48
# define FLAG 70

# define MIN_MAP_HIEGHT 3
# define MAX_MAP_HIEGHT 21
# define MIN_MAP_WIDTH 3
# define MAX_MAP_WIDTH 40

# define ERROR "Error "
# define FILE_ERROR "Unable to Read File Data!! "
# define FILE_NAME_ERROR "Invalid Map File Format!! "
# define WIDTH_NOT_SAME "Width of Map is not Same for all Rows!!\n"
# define MAP_SIZE_ISSUE "Map is Either too Big or too Small to be Displayed!! "
# define UNKNOWN_CHAR "Found an Unknown Variable in Map!!\n"
# define FOUR_SIDE_WALL "Map should be closed with Walls from all 4 sides!!\n"
# define CAN_NOT_COLLECT "All Collectibles cannot be collected!!\n"
# define EXIT_NOT_REACHABLE "Player cannot reach Exit!!\n"
# define ZERO_COLLECT "No. of Collectibles cannot be less than 1\n"
# define ONE_EXIT "No. of Exits should only be 1\n"
# define ONE_PLAYER "No. of Players should only be 1\n"
# define PRESSED_ESC "Ohhh... You Pressed Esc!!\n"
# define RED_CROSS_CLICKED "Ohhh... You Closed the game Window!!\n"
# define PLAYER_WON "Yeah... You Won!!\n"

typedef struct s_img
{
	void	*wall;
	void	*exit;
	void	*player;
	void	*collect;
	void	*back;
	void	*lock;
	int		img_h;
	int		img_w;
}	t_img;

typedef struct s_map
{
	int	h;
	int	w;
	int	exit;
	int	exit_pos;
	int	collect;
	int	player;
}	t_map;

typedef struct s_game
{
	void	*mlx_connection;
	void	*mlx_window;
	char	**map;
	char	*relative_path;
	t_map	*map_str;
	t_img	*img;
	int		moves;
	char	*put_moves;
	char	*put_collect;
	int		to_collect;
	int		to_exit;
	int		over;
	int		player_x;
	int		player_y;
}	t_data;

void	game_window(t_data *game);
void	create_image(t_data *game);
void	display_image(t_data *game, int i, int j);
int		key_hooks(int keysym, t_data *game);
int		red_cross(void *data);
int		read_esc(int keysym, void *win);
int		check_map_file(const char *map);
int		exit_game_after_window(t_data *data);
int		exit_game_before_window(t_data *win);
void	free_map(char **map);
int		error_message(int code);
char	**load_map(char *file);
int		check_errors(t_data *win);
int		check_map_dimensions(t_data *win);
void	init_player(t_data *win);
void	display_exit(t_data *win, int y, int x);
int		check_count_of_components(t_data *win);
int		count_components(t_data *win, int h, int w);
int		check_boundary_walls(t_data *win);
int		check_components(t_data *win);
void	check_exit_pos(t_data *win, int x, int y);
void	check_exit_pos1(t_data *win, int x, int y);
int		check_path(t_data *win);
void	check_move(char **map_dup, int x, int y, t_data *win);
int		key_hooks(int key, t_data *win);
void	move_up(t_data *win);
void	move_down(t_data *win);
void	move_left(t_data *win);
void	move_right(t_data *win);
void	update_player(t_data *win, int key);
void	calculate_moves(t_data *win, int x, int y);
void	game_status(t_data *win);
#endif