/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 12:11:17 by vabatist          #+#    #+#             */
/*   Updated: 2025/04/02 12:07:36 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Main function to validate the map.
 */
void	validate_map(t_map *map)
{
	check_rectangular(map);
	count_map_elements(map);
	validate_map_format(map);
	validate_borders(map);
}

/**
 * Checks if the map is rectangular.
 */
void	check_rectangular(t_map *map)
{
	int	i;
	int	line_length;

	i = 0;
	while (i < map->rows)
	{
		line_length = ft_strlen(map->data[i]);
		if (i == 0)
			map->cols = line_length;
		else if (line_length != map->cols)
			error_exit_map("Map is not rectangular", map);
		i++;
	}
}

/**
 * Counts map elements and validates characters.
 */
void	count_map_elements(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->count_p = 0;
	map->count_e = 0;
	map->count_c = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!is_valid_char(map->data[i][j]))
				error_exit_map("Map contains invalid characters", map);
			if (map->data[i][j] == 'P')
				map->count_p++;
			else if (map->data[i][j] == 'E')
				map->count_e++;
			else if (map->data[i][j] == 'C')
				map->count_c++;
			j++;
		}
		i++;
	}
}

/**
 * Verifies if the map is rectangular and contains only valid characters.
 */
void	validate_map_format(t_map *map)
{
	check_rectangular(map);
	count_map_elements(map);
	if (map->count_p != 1 || map->count_e != 1 || map->count_c < 1)
		error_exit_map("Map must have 1 P, 1 E, and at least 1 C", map);
}

/**
 * Verifies if the map is surrounded by walls.
 */
void	validate_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (map->data[0][i] != '1' || map->data[map->rows - 1][i] != '1')
			error_exit_map("Map is not surrounded by walls", map);
		i++;
	}
	i = 0;
	while (i < map->rows)
	{
		if (map->data[i][0] != '1' || map->data[i][map->cols - 1] != '1')
			error_exit_map("Map is not surrounded by walls", map);
		i++;
	}
	ft_printf("Borders validated successfully.\n");
}
