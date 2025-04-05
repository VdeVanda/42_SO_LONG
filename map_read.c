/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:54:10 by vabatist          #+#    #+#             */
/*   Updated: 2025/04/02 11:46:30 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>  // Include the standard I/O library
#include <string.h> // Include the string library for debugging

/**
 * Reads the map file line by line and stores it in the map structure.
 */
void	read_map_from_file(const char *filename, t_map *map)
{
	int	fd;
	int	i;

	fd = open_map_file(filename);
	map->rows = count_lines_in_file(fd);
	allocate_map_data(map);
	fd = open_map_file(filename);
	i = 0;
	while (i < map->rows)
	{
		read_map_line(fd, map, i);
		i++;
	}
	close(fd);
}

/**
 * Reads a line from the map file and stores it in the map structure.
 */
void	read_map_line(int fd, t_map *map, int index)
{
	char	*newline_pos;

	map->data[index] = get_next_line(fd);
	if (!map->data[index])
		error_exit("Failed to read line from file");
	newline_pos = ft_strchr(map->data[index], '\n');
	if (newline_pos)
		*newline_pos = '\0';
	if (index == 0)
		map->cols = ft_strlen(map->data[index]);
	else if ((int)ft_strlen(map->data[index]) != map->cols)
	{
		map->rows = index + 1;
		error_exit_map("Map is not rectangular", map);
	}
}
