/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:29:18 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 15:47:44 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_enemy_n_collecible(t_data *win, size_t t)
{
	if (t % 15 == 1)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E1.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_B3.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 2)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E2.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_B2.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 3)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E3.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_B1.xpm", &win->img->img_w, &win->img->img_h);
	}
	else
		update_enemy_n_collecible1(win, t);
}

void	update_enemy_n_collecible1(t_data *win, size_t t)
{
	if (t % 15 == 4)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E4.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 5)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E5.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_U1.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 6)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E6.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_U2.xpm", &win->img->img_w, &win->img->img_h);
	}
	else
		update_enemy_n_collecible2(win, t);
}

void	update_enemy_n_collecible2(t_data *win, size_t t)
{
	if (t % 15 == 7)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E7.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_U3.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 8)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E8.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_U4.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 9)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E9.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_U3.xpm", &win->img->img_w, &win->img->img_h);
	}
	else
		update_enemy_n_collecible3(win, t);
}

void	update_enemy_n_collecible3(t_data *win, size_t t)
{
	if (t % 15 == 10)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E10.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_U2.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 11)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E11.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_U1.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 12)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E12.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star.xpm", &win->img->img_w, &win->img->img_h);
	}
	else
		update_enemy_n_collecible4(win, t);
}

void	update_enemy_n_collecible4(t_data *win, size_t t)
{
	if (t % 15 == 13)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E13.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 14)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E14.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_B1.xpm", &win->img->img_w, &win->img->img_h);
	}
	else if (t % 15 == 0)
	{
		win->img->enemy = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Enemy/E15.xpm", &win->img->img_w, &win->img->img_h);
		win->img->collect = mlx_xpm_file_to_image(win->mlx_connection, \
		"textures/Collectible/Star_B2.xpm", &win->img->img_w, &win->img->img_h);
	}
}
