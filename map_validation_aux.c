/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_aux.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:05:28 by vabatist          #+#    #+#             */
/*   Updated: 2025/04/02 17:25:26 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Validates the path in the map.
 */
void	validate_path(t_map *map)
{
	char	**copy;
	t_flood	flood;

	copy = malloc(sizeof(char *) * map->rows);
	if (!copy)
		error_exit_map("Memory allocation failed", map);
	copy_map(copy, map);
	flood.collectibles = map->count_c;
	flood.exit_found = 0;
	find_player_and_fill(copy, map, &flood);
	free_copy(copy, map->rows);
	if (flood.collectibles > 0 || flood.exit_found == 0)
		error_exit_map("Invalid path in map", map);
	ft_printf("Path validated successfully.\n");
	ft_printf("Map initialization complete.\n");
	ft_printf("\nWELCOME TO SO LONG!\n");
	ft_printf("\nCollect all eggs on the map\n");
	ft_printf("and then escape by choosing\n");
	ft_printf("the shortest possible route.\n");
}

/**
 * Finds the player position and starts the flood fill algorithm.
 */
void	find_player_and_fill(char **copy, t_map *map, t_flood *flood)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (copy[y][x] == 'P')
			{
				flood_fill(copy, x, y, flood);
				return ;
			}
			x++;
		}
		y++;
	}
}

/**
 * Copies the map to be used in the flood fill algorithm.
 */
void	copy_map(char **copy, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		copy[i] = ft_strdup(map->data[i]);
		if (!copy[i])
			error_exit_map("Memory allocation failed", map);
		i++;
	}
}

/**
 * Flood fill algorithm to check if the map is solvable.
 */
void	flood_fill(char **map, int x, int y, t_flood *flood)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C')
		flood->collectibles--;
	if (map[y][x] == 'E')
	{
		flood->exit_found = 1;
		return ;
	}
	map[y][x] = 'X';
	flood_fill(map, x + 1, y, flood);
	flood_fill(map, x - 1, y, flood);
	flood_fill(map, x, y + 1, flood);
	flood_fill(map, x, y - 1, flood);
}

/**
 * Verifies if a char is a valid map element.
 */
int	is_valid_char(char c)
{
	return (ft_strchr(VALID_CHARS, c) != NULL);
}
