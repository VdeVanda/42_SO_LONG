/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabatist <vabatist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:49 by vabatist          #+#    #+#             */
/*   Updated: 2025/03/29 16:54:20 by vabatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, t_coordinates current,
		t_coordinates destination)
{
	t_map	*map;

	map = &(game->map);
	if (map->data[destination.y][destination.x] == 'C')
		map->count_c--;
	else if (map->data[destination.y][destination.x] == 'E'
		&& map->count_c == 0)
	{
		free_game(game);
		exit(0);
	}
	map->data[destination.y][destination.x] = 'P';
	map->data[current.y][current.x] = '0';
	game->count_moves++;
	ft_printf("Moves: %d\n", game->count_moves);
}

void	move_left(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x - 1;
	destination.y = current.y;
	check_restrictions(game, current, destination);
}

void	move_up(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x;
	destination.y = current.y - 1;
	check_restrictions(game, current, destination);
}

void	move_rigth(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x + 1;
	destination.y = current.y;
	check_restrictions(game, current, destination);
}

void	move_down(t_game *game)
{
	t_coordinates	current;
	t_coordinates	destination;

	current = get_player_position(game->map);
	destination.x = current.x;
	destination.y = current.y + 1;
	check_restrictions(game, current, destination);
}
