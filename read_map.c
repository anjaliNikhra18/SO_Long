/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:30:29 by aneekhra          #+#    #+#             */
/*   Updated: 2024/05/17 18:05:50 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_file(const char *map)
{
	int	i;
	int	fd;

	i = 0;
	while (map[i] != '\0')
		i++;
	fd = ft_strncmp(&map[i - 4], ".ber", 4);
	if (fd != 0)
	{
		error_message(8);
		return (0);
	}
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		error_message(2);
		return (0);
	}
	close(fd);
	return (1);
}

char	*get_map(int fd)
{
	char	*temp;
	char	*line;
	char	*new_temp;

	temp = NULL;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (temp)
		{
			new_temp = ft_strjoin(temp, line);
			free(line);
		}
		else
			new_temp = line;
		free(temp);
		temp = new_temp;
	}
	close(fd);
	return (temp);
}

char	**load_map(char *file)
{
	int		fd;
	char	*map;
	char	**map_array;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error_message(2);
		return (NULL);
	}
	map = get_map(fd);
	if (!map)
		return (NULL);
	map_array = ft_split(map, '\n');
	free(map);
	return (map_array);
}
